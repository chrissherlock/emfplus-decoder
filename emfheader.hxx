#include <iostream>
#include <fstream>
#include <cwchar>
#include <string>

#ifndef EMFHEADER
#define EMFHEADER

using namespace std;

typedef struct {
    int left;
    int top;
    int right;
    int bottom;
} RectL;

typedef struct {
    int cx;
    int cy;
} SizeL;

/* structure of an EMF file's header record is:
    Type                        (unsigned int   - 4 bytes)
        * note: for EMR_HEADER this MUST be 0x00000001
    Size                        (unsigned int   - 4 bytes)
        * note: 88 bytes  = EmfMetafileHeader record (Contains Header object)
                100 bytes = EmfMetafileHeaderExtension1 (contains EmfMetafileHeader record)
                108 bytes = EmfMetafileHeaderExtension2 (contains EmfMetafileHeaderExtension1 record)
    EmfMetafileHeader           (Header type    - 80 bytes)
        - Bounds                (RectL object   - 16 bytes)
        - Frame                 (RectL object   - 16 bytes)
        - RecordSignature       (unsigned int   - 4 bytes)
            * note: MUST be ENHMETA_SIGNATURE
        - Version               (unsigned int   - 4 bytes)
            * note: SHOULD be 0x00010000
        - Bytes                 (unsigned int   - 4 bytes)
            * note: size of metafile, in bytes
        - Records               (unsigned int   - 4 bytes)
        - Handles               (unsigned short - 2 bytes)
            * note: number of graphics objects in metafile
        - Reserved              (unsigned short - 2 bytes)
            * note: MUST be 0x0000
        - nDescription          (unsigned int   - 4 bytes)
            * note: 0 if no description, size of description
        - offDescription        (unsigned int   - 4 bytes)
            * specifies offset from beginning of recrod to array that contains description
        - nPalEntries           (unsigned int   - 4 bytes)
            * number of entries in metafile palette
        - Device                (SizeL object   - 8 bytes)
            * size of reference device, in pixels
        - Millimeters           (SizeL object   - 8 bytes)
    EmfMetafileHeaderExtension1 (optional)
        - cbPixelFormat         (unsigned int   - 4 bytes)
            * MUST by 0x00000000 if no pixel format is set
        - offPixelFormat        (unsigned int   - 4 bytes)
            * MUST by 0x00000000 if no pixel format is set
        - bOpenGL               (unsigned int   - 4 bytes)
            * 0x00000000 - no OpenGL records present
            * 0x00000001 - OpenGL records present
    EmfMetafileHeaderExtension2 (optional)
        - MicroMetersX          (int            - 4 bytes)
        - MicroMetersY          (int            - 4 bytes)
    
    NOTE: the next four fields are used by EmfMetafileHeaderExtension1

    EmfDescriptionBuffer        (optional and variable)
        * note: labeled UndefinedSpace, optional and MUST be ignored
    EmfDescription              (variable, optional)
        * null-terminated Unicode UTF16-LE string
        * pointed at by offDescription and nDescription fields

    EmfPixelFormatBuffer
        * note: labeled UndefinedSpace, optional and MUST be ignored
    EmfPixelFormat              (PixelFormatDescription - 40 bytes)

    EmfHeaderRecordBuffer       (variable byte array in multiples of 4 bytes - see size above for more info)
        - EmfHeaderRecordParm   (char array     - variable)
        - AlignmentPadding      (char array     - pads record to make size of EmfHeaderRecordBuffer a 

*/

// note that [MS-EMF] states in section 2.1.14 that this should
// be an enumeration... I disagree!
#define ENHMETA_SIGNATURE  0x464D4520
#define EPS_SIGNATURE      0x46535045

// header type enumeration - defined in [MS-EMF] section 2.1.1 
// RecordType Enumeration
#define EMR_HEADER 0x00000001
#define EMR_POLYBEZIER 0x00000002
#define EMR_POLYGON 0x00000003
#define EMR_POLYLINE 0x00000004
#define EMR_POLYBEZIERTO 0x00000005
#define EMR_POLYLINETO 0x00000006
#define EMR_POLYPOLYLINE 0x00000007
#define EMR_POLYPOLYGON 0x00000008
#define EMR_SETWINDOWEXTEX 0x00000009
#define EMR_SETWINDOWORGEX 0x0000000A
#define EMR_SETVIEWPORTEXTEX 0x0000000B
#define EMR_SETVIEWPORTORGEX 0x0000000C
#define EMR_SETBRUSHORGEX 0x0000000D
#define EMR_EOF 0x0000000E
#define EMR_SETPIXELV 0x0000000F
#define EMR_SETMAPPERFLAGS 0x00000010
#define EMR_SETMAPMODE 0x00000011
#define EMR_SETBKMODE 0x00000012
#define EMR_SETPOLYFILLMODE 0x00000013
#define EMR_SETROP2 0x00000014
#define EMR_SETSTRETCHBLTMODE 0x00000015
#define EMR_SETTEXTALIGN 0x00000016
#define EMR_SETCOLORADJUSTMENT 0x00000017
#define EMR_SETTEXTCOLOR 0x00000018
#define EMR_SETBKCOLOR 0x00000019
#define EMR_OFFSETCLIPRGN 0x0000001A
#define EMR_MOVETOEX 0x0000001B
#define EMR_SETMETARGN 0x0000001C
#define EMR_EXCLUDECLIPRECT 0x0000001D
#define EMR_INTERSECTCLIPRECT 0x0000001E
#define EMR_SCALEVIEWPORTEXTEX 0x0000001F
#define EMR_SCALEWINDOWEXTEX 0x00000020
#define EMR_SAVEDC 0x00000021
#define EMR_RESTOREDC 0x00000022
#define EMR_SETWORLDTRANSFORM 0x00000023
#define EMR_MODIFYWORLDTRANSFORM 0x00000024
#define EMR_SELECTOBJECT 0x00000025
#define EMR_CREATEPEN 0x00000026
#define EMR_CREATEBRUSHINDIRECT 0x00000027
#define EMR_DELETEOBJECT 0x00000028
#define EMR_ANGLEARC 0x00000029
#define EMR_ELLIPSE 0x0000002A
#define EMR_RECTANGLE 0x0000002B
#define EMR_ROUNDRECT 0x0000002C
#define EMR_ARC 0x0000002D
#define EMR_CHORD 0x0000002E
#define EMR_PIE 0x0000002F
#define EMR_SELECTPALETTE 0x00000030
#define EMR_CREATEPALETTE 0x00000031
#define EMR_SETPALETTEENTRIES 0x00000032
#define EMR_RESIZEPALETTE 0x00000033
#define EMR_REALIZEPALETTE 0x00000034
#define EMR_EXTFLOODFILL 0x00000035
#define EMR_LINETO 0x00000036
#define EMR_ARCTO 0x00000037
#define EMR_POLYDRAW 0x00000038
#define EMR_SETARCDIRECTION 0x00000039
#define EMR_SETMITERLIMIT 0x0000003A
#define EMR_BEGINPATH 0x0000003B
#define EMR_ENDPATH 0x0000003C
#define EMR_CLOSEFIGURE 0x0000003D
#define EMR_FILLPATH 0x0000003E
#define EMR_STROKEANDFILLPATH 0x0000003F
#define EMR_STROKEPATH 0x00000040
#define EMR_FLATTENPATH 0x00000041
#define EMR_WIDENPATH 0x00000042
#define EMR_SELECTCLIPPATH 0x00000043
#define EMR_ABORTPATH 0x00000044
#define EMR_COMMENT 0x00000046
#define EMR_FILLRGN 0x00000047
#define EMR_FRAMERGN 0x00000048
#define EMR_INVERTRGN 0x00000049
#define EMR_PAINTRGN 0x0000004A
#define EMR_EXTSELECTCLIPRGN 0x0000004B
#define EMR_BITBLT 0x0000004C
#define EMR_STRETCHBLT 0x0000004D
#define EMR_MASKBLT 0x0000004E
#define EMR_PLGBLT 0x0000004F
#define EMR_SETDIBITSTODEVICE 0x00000050
#define EMR_STRETCHDIBITS 0x00000051
#define EMR_EXTCREATEFONTINDIRECTW 0x00000052
#define EMR_EXTTEXTOUTA 0x00000053
#define EMR_EXTTEXTOUTW 0x00000054
#define EMR_POLYBEZIER16 0x00000055
#define EMR_POLYGON16 0x00000056
#define EMR_POLYLINE16 0x00000057
#define EMR_POLYBEZIERTO16 0x00000058
#define EMR_POLYLINETO16 0x00000059
#define EMR_POLYPOLYLINE16 0x0000005A
#define EMR_POLYPOLYGON16 0x0000005B
#define EMR_POLYDRAW16 0x0000005C
#define EMR_CREATEMONOBRUSH 0x0000005D
#define EMR_CREATEDIBPATTERNBRUSHPT 0x0000005E
#define EMR_EXTCREATEPEN 0x0000005F
#define EMR_POLYTEXTOUTA 0x00000060
#define EMR_POLYTEXTOUTW 0x00000061
#define EMR_SETICMMODE 0x00000062
#define EMR_CREATECOLORSPACE 0x00000063
#define EMR_SETCOLORSPACE 0x00000064
#define EMR_DELETECOLORSPACE 0x00000065
#define EMR_GLSRECORD 0x00000066
#define EMR_GLSBOUNDEDRECORD 0x00000067
#define EMR_PIXELFORMAT 0x00000068
#define EMR_DRAWESCAPE 0x00000069
#define EMR_EXTESCAPE 0x0000006A
#define EMR_SMALLTEXTOUT 0x0000006C
#define EMR_FORCEUFIMAPPING 0x0000006D
#define EMR_NAMEDESCAPE 0x0000006E
#define EMR_COLORCORRECTPALETTE 0x0000006F
#define EMR_SETICMPROFILEA 0x00000070
#define EMR_SETICMPROFILEW 0x00000071
#define EMR_ALPHABLEND 0x00000072
#define EMR_SETLAYOUT 0x00000073
#define EMR_TRANSPARENTBLT 0x00000074
#define EMR_GRADIENTFILL 0x00000076
#define EMR_SETLINKEDUFIS 0x00000077
#define EMR_SETTEXTJUSTIFICATION 0x00000078
#define EMR_COLORMATCHTOTARGETW 0x00000079
#define EMR_CREATECOLORSPACEW 0x0000007A

typedef struct {
    RectL           *bounds;
    RectL           *frame;
    unsigned int    recordSignature;
    unsigned int    version;
    unsigned int    bytes;
    unsigned int    records;
    unsigned int    handles;
    unsigned int    reserved;
    unsigned int    nDescription;
    unsigned int    offDescription;
    unsigned int    nPalEntries;
    SizeL           *device;
    SizeL           *millimeters;
} EmfMetafileHeader;

typedef struct {
    unsigned int    cbPixelFormat;
    unsigned int    offPixelFormat;
    unsigned int    bOpenGL;
} EmfMetafileHeaderExt1;

typedef struct {
    unsigned int    microMetersX;
    unsigned int    microMetersY;
} EmfMetafileHeaderExt2;

typedef basic_string<wchar_t> UTF_16LE;

typedef struct {
    UTF_16LE        *description;
} EmfMetafileHeaderDesc;

typedef struct {
    unsigned int           type;
    unsigned int           size;
    EmfMetafileHeader     *header;
    EmfMetafileHeaderExt1 *headerExt1;
    EmfMetafileHeaderExt2 *headerExt2;
    EmfMetafileHeaderDesc *headerDesc;
} Header;

#endif
