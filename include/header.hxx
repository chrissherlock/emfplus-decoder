#include "defs.hxx"
#include "wmf.hxx"

#ifndef EMFHEADER
#define EMFHEADER

using namespace std;

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

typedef struct {
    RectL           *bounds;
    RectL           *frame;
    unsigned int    recordSignature;
    unsigned int    version;
    unsigned int    bytes;
    unsigned int    records;
    unsigned short  handles;
    unsigned short  reserved;
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
    unsigned PFD_DOUBLEBUFFER           : 1;
    unsigned PFD_STEREO                 : 1;
    unsigned PFD_DRAW_TO_WINDOW         : 1;
    unsigned PFD_DRAW_TO_BITMAP         : 1;
    unsigned PFD_SUPPORT_GDI            : 1;
    unsigned PFD_SUPPORT_OPENGL         : 1;
    unsigned PFD_GENERIC_FORMAT         : 1;
    unsigned PFD_NEED_PALETTE           : 1;
    unsigned PFD_NEED_SYSTEM_PALETTE    : 1;
    unsigned PFD_SWAP_EXCHANGE          : 1;
    unsigned PFD_SWAP_COPY              : 1;
    unsigned PFD_SWAP_LAYER_BUFFERS     : 1;
    unsigned PFD_GENERIC_ACCELERATED    : 1;
    unsigned PFD_SUPPORT_DIRECTDRAW     : 1;
    unsigned PFD_DIRECT3D_ACCELERATED   : 1;
    unsigned PFD_SUPPORT_COMPOSITION    : 1;
    unsigned PFD_DEPTH_DONTCARE         : 1;
    unsigned PFD_DOUBLEBUFFER_DONTCARE  : 1;
    unsigned PFD_STEREO_DONTCARE        : 1;
} PFFlags; 

typedef enum {
    PFD_TYPE_RGBA = 0x00,
    PFD_TYPE_COLORINDEX = 0x01
} PFPixelType;

typedef struct {
    unsigned short  nSize;
    unsigned short  nVersion;
    PFFlags         dwFlags;
    PFPixelType     iPixelType;
    char            cColorBits;
    char            cRedBits;
    char            cRedShift;
    char            cGreenBits;
    char            cGreenShift;
    char            cBlueBits;
    char            cBlueShift;
    char            cAlphaBits;
    char            cAlphaShift;
    char            cAccumBits;
    char            cAccumRedBits;
    char            cAccumGreenBits;
    char            cAccumBlueBits;
    char            cAccumAlphaBits;
    char            cDepthBits;
    char            cStencilBits;
    char            cAuxBuffers;
    char            iLayerType;
    char            bReserved;
    int             dwLayerMask;
    int             dwVisibleMask;
    int             dwDamageMask;
} PixelFormatDescriptor;  

typedef struct {
    unsigned int           type;
    unsigned int           size;
    EmfMetafileHeader     *header;
    EmfMetafileHeaderExt1 *headerExt1;
    EmfMetafileHeaderExt2 *headerExt2;
    EmfMetafileHeaderDesc *headerDesc;
    PixelFormatDescriptor *headerPxlFmtDesc;
} Header;

#endif
