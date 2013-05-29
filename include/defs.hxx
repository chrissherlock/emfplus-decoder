#ifndef EMFDEFS
#define EMFDEFS

using namespace std;

// note that [MS-EMF] states in section 2.1.14 that this should
// be an enumeration... I disagree!
#define ENHMETA_SIGNATURE           0x464D4520
#define EPS_SIGNATURE               0x46535045

// header type enumeration - defined in [MS-EMF] section 2.1.1 
// RecordType Enumeration
#define EMR_HEADER                  0x00000001
#define EMR_POLYBEZIER              0x00000002
#define EMR_POLYGON                 0x00000003
#define EMR_POLYLINE                0x00000004
#define EMR_POLYBEZIERTO            0x00000005
#define EMR_POLYLINETO              0x00000006
#define EMR_POLYPOLYLINE            0x00000007
#define EMR_POLYPOLYGON             0x00000008
#define EMR_SETWINDOWEXTEX          0x00000009
#define EMR_SETWINDOWORGEX          0x0000000A
#define EMR_SETVIEWPORTEXTEX        0x0000000B
#define EMR_SETVIEWPORTORGEX        0x0000000C
#define EMR_SETBRUSHORGEX           0x0000000D
#define EMR_EOF                     0x0000000E
#define EMR_SETPIXELV               0x0000000F
#define EMR_SETMAPPERFLAGS          0x00000010
#define EMR_SETMAPMODE              0x00000011
#define EMR_SETBKMODE               0x00000012
#define EMR_SETPOLYFILLMODE         0x00000013
#define EMR_SETROP2                 0x00000014
#define EMR_SETSTRETCHBLTMODE       0x00000015
#define EMR_SETTEXTALIGN            0x00000016
#define EMR_SETCOLORADJUSTMENT      0x00000017
#define EMR_SETTEXTCOLOR            0x00000018
#define EMR_SETBKCOLOR              0x00000019
#define EMR_OFFSETCLIPRGN           0x0000001A
#define EMR_MOVETOEX                0x0000001B
#define EMR_SETMETARGN              0x0000001C
#define EMR_EXCLUDECLIPRECT         0x0000001D
#define EMR_INTERSECTCLIPRECT       0x0000001E
#define EMR_SCALEVIEWPORTEXTEX      0x0000001F
#define EMR_SCALEWINDOWEXTEX        0x00000020
#define EMR_SAVEDC                  0x00000021
#define EMR_RESTOREDC               0x00000022
#define EMR_SETWORLDTRANSFORM       0x00000023
#define EMR_MODIFYWORLDTRANSFORM    0x00000024
#define EMR_SELECTOBJECT            0x00000025
#define EMR_CREATEPEN               0x00000026
#define EMR_CREATEBRUSHINDIRECT     0x00000027
#define EMR_DELETEOBJECT            0x00000028
#define EMR_ANGLEARC                0x00000029
#define EMR_ELLIPSE                 0x0000002A
#define EMR_RECTANGLE               0x0000002B
#define EMR_ROUNDRECT               0x0000002C
#define EMR_ARC                     0x0000002D
#define EMR_CHORD                   0x0000002E
#define EMR_PIE                     0x0000002F
#define EMR_SELECTPALETTE           0x00000030
#define EMR_CREATEPALETTE           0x00000031
#define EMR_SETPALETTEENTRIES       0x00000032
#define EMR_RESIZEPALETTE           0x00000033
#define EMR_REALIZEPALETTE          0x00000034
#define EMR_EXTFLOODFILL            0x00000035
#define EMR_LINETO                  0x00000036
#define EMR_ARCTO                   0x00000037
#define EMR_POLYDRAW                0x00000038
#define EMR_SETARCDIRECTION         0x00000039
#define EMR_SETMITERLIMIT           0x0000003A
#define EMR_BEGINPATH               0x0000003B
#define EMR_ENDPATH                 0x0000003C
#define EMR_CLOSEFIGURE             0x0000003D
#define EMR_FILLPATH                0x0000003E
#define EMR_STROKEANDFILLPATH       0x0000003F
#define EMR_STROKEPATH              0x00000040
#define EMR_FLATTENPATH             0x00000041
#define EMR_WIDENPATH               0x00000042
#define EMR_SELECTCLIPPATH          0x00000043
#define EMR_ABORTPATH               0x00000044
#define EMR_COMMENT                 0x00000046
#define EMR_FILLRGN                 0x00000047
#define EMR_FRAMERGN                0x00000048
#define EMR_INVERTRGN               0x00000049
#define EMR_PAINTRGN                0x0000004A
#define EMR_EXTSELECTCLIPRGN        0x0000004B
#define EMR_BITBLT                  0x0000004C
#define EMR_STRETCHBLT              0x0000004D
#define EMR_MASKBLT                 0x0000004E
#define EMR_PLGBLT                  0x0000004F
#define EMR_SETDIBITSTODEVICE       0x00000050
#define EMR_STRETCHDIBITS           0x00000051
#define EMR_EXTCREATEFONTINDIRECTW  0x00000052
#define EMR_EXTTEXTOUTA             0x00000053
#define EMR_EXTTEXTOUTW             0x00000054
#define EMR_POLYBEZIER16            0x00000055
#define EMR_POLYGON16               0x00000056
#define EMR_POLYLINE16              0x00000057
#define EMR_POLYBEZIERTO16          0x00000058
#define EMR_POLYLINETO16            0x00000059
#define EMR_POLYPOLYLINE16          0x0000005A
#define EMR_POLYPOLYGON16           0x0000005B
#define EMR_POLYDRAW16              0x0000005C
#define EMR_CREATEMONOBRUSH         0x0000005D
#define EMR_CREATEDIBPATTERNBRUSHPT 0x0000005E
#define EMR_EXTCREATEPEN            0x0000005F
#define EMR_POLYTEXTOUTA            0x00000060
#define EMR_POLYTEXTOUTW            0x00000061
#define EMR_SETICMMODE              0x00000062
#define EMR_CREATECOLORSPACE        0x00000063
#define EMR_SETCOLORSPACE           0x00000064
#define EMR_DELETECOLORSPACE        0x00000065
#define EMR_GLSRECORD               0x00000066
#define EMR_GLSBOUNDEDRECORD        0x00000067
#define EMR_PIXELFORMAT             0x00000068
#define EMR_DRAWESCAPE              0x00000069
#define EMR_EXTESCAPE               0x0000006A
#define EMR_SMALLTEXTOUT            0x0000006C
#define EMR_FORCEUFIMAPPING         0x0000006D
#define EMR_NAMEDESCAPE             0x0000006E
#define EMR_COLORCORRECTPALETTE     0x0000006F
#define EMR_SETICMPROFILEA          0x00000070
#define EMR_SETICMPROFILEW          0x00000071
#define EMR_ALPHABLEND              0x00000072
#define EMR_SETLAYOUT               0x00000073
#define EMR_TRANSPARENTBLT          0x00000074
#define EMR_GRADIENTFILL            0x00000076
#define EMR_SETLINKEDUFIS           0x00000077
#define EMR_SETTEXTJUSTIFICATION    0x00000078
#define EMR_COLORMATCHTOTARGETW     0x00000079
#define EMR_CREATECOLORSPACEW       0x0000007A

#define EMR_COMMENT_EMFSPOOL        0x00000000
#define EMR_COMMENT_EMFPLUS         0x2B464D45
#define EMR_COMMENT_PUBLIC          0x43494447

#endif
