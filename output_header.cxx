#include <iostream>
#include <fstream>
#include <cwchar>

#include "header.hxx"
#include "header_output.hxx"

using namespace std;

std::ostream& operator << (std::ostream &s, Header &header) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "EMR_HEADER        " << endl
      << "==================================" << endl
      << "Type:             " << std::hex << std::showbase << header.type << endl
      << "Size:             " << std::dec << header.size << endl << endl;
    
    s.setf(basefield);

    s << *header.header << endl;

    if (header.headerExt1) {
        s << *header.headerExt1 << endl;
        if (header.headerExt1->offPixelFormat != 0) {
            s << *header.headerPxlFmtDesc << endl;
        }
    }

    if (header.headerExt2) {
        s << *header.headerExt2 << endl;
    }

    if (header.header->offDescription != 0) {
        s << *header.headerDesc << endl;
    }

    return s;
}

std::ostream& operator << (std::ostream &s, EmfMetafileHeader &emfHeader) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "Bounds:           " << endl
      << "    Left:         " << emfHeader.bounds->left << endl
      << "    Top:          " << emfHeader.bounds->top << endl
      << "    Right:        " << emfHeader.bounds->right << endl
      << "    Bottom:       " << emfHeader.bounds->bottom << endl
      << "Frame:            " << endl
      << "    Left:         " << emfHeader.frame->left << endl
      << "    Top:          " << emfHeader.frame->top << endl
      << "    Right:        " << emfHeader.frame->right << endl
      << "    Bottom:       " << emfHeader.frame->bottom << endl
      << "RecordSignature:  " << std::hex << std::showbase << emfHeader.recordSignature << endl
      << "Version:          " << emfHeader.version << endl
      << "Bytes:            " << std::dec << emfHeader.bytes << endl
      << "Records:          " << emfHeader.records << endl
      << "Handles:          " << emfHeader.handles << endl
      << "Reserved:         " << std::hex << std::showbase << emfHeader.reserved << endl
      << "Desc. size:       " << std::dec << emfHeader.nDescription << endl
      << "Desc. offset:     " << std::hex << std::showbase << emfHeader.offDescription << endl
      << "PAL entries:      " << std::dec << emfHeader.nPalEntries << endl
      << "Size (dev units): " << endl
      << "    cx:           " << emfHeader.device->cx << endl
      << "    cy:           " << emfHeader.device->cy << endl
      << "Size (mm):        " << endl
      << "    cx:           " << emfHeader.millimeters->cx << "mm" << endl
      << "    cy:           " << emfHeader.millimeters->cy << "mm" << endl; 
    
    s.setf(basefield);
    return s;
}

std::ostream& operator << (std::ostream &s, EmfMetafileHeaderExt1 &emfHeaderExt1) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "Header Extension 1" << endl
      << "==================================" << endl
      << "cbPixelFormat:   " << emfHeaderExt1.cbPixelFormat << endl
      << "offPixelFormat:  " << emfHeaderExt1.offPixelFormat << endl;

    s.setf(basefield);
    return s;
}

std::ostream& operator << (std::ostream &s, EmfMetafileHeaderExt2 &emfHeaderExt2) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "Header Extension 2" << endl
      << "==================================" << endl
      << "microMetersX:    " << emfHeaderExt2.microMetersX << endl
      << "microMetersY:    " << emfHeaderExt2.microMetersY << endl;

    s.setf(basefield);
    return s;
}

std::ostream& operator << (std::ostream &s, EmfMetafileHeaderDesc &emfHeaderDesc) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "EMF Description" << endl
      << "==================================" << endl
      << *emfHeaderDesc.description->c_str() << endl;

    s.setf(basefield);
    return s;
}


std::ostream& operator << (std::ostream& s, PFFlags &flags) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "Pixel format flags:" << endl
      << "\tPFD_DOUBLEBUFFER: " << (flags.PFD_DOUBLEBUFFER ? "on" : "off") << endl
      << "\tPFD_STEREO: " << (flags.PFD_STEREO ? "on" : "off") << endl
      << "\tPFD_DRAW_TO_WINDOW: " << (flags.PFD_DRAW_TO_WINDOW ? "on" : "off") << endl
      << "\tPFD_DRAW_TO_BITMAP: " << (flags.PFD_DRAW_TO_BITMAP ? "on" : "off") << endl
      << "\tPFD_SUPPORT_GDI: " << (flags.PFD_SUPPORT_GDI ? "on" : "off") << endl
      << "\tPFD_SUPPORT_OPENGL: " << (flags.PFD_SUPPORT_OPENGL ? "on" : "off") << endl
      << "\tPFD_GENERIC_FORMAT: " << (flags.PFD_GENERIC_FORMAT ? "on" : "off") << endl
      << "\tPFD_NEED_PALETTE: " << (flags.PFD_NEED_PALETTE ? "on" : "off") << endl
      << "\tPFD_NEED_SYSTEM_PALETTE: " << (flags.PFD_NEED_SYSTEM_PALETTE ? "on" : "off") << endl
      << "\tPFD_SWAP_EXCHANGE: " << (flags.PFD_SWAP_EXCHANGE ? "on" : "off") << endl
      << "\tPFD_SWAP_COPY: " << (flags.PFD_SWAP_COPY ? "on" : "off") << endl
      << "\tPFD_SWAP_LAYER_BUFFERS: " << (flags.PFD_SWAP_LAYER_BUFFERS ? "on" : "off") << endl
      << "\tPFD_GENERIC_ACCELERATED: " << (flags.PFD_GENERIC_ACCELERATED ? "on" : "off") << endl
      << "\tPFD_SWAP_DIRECTDRAW: " << (flags.PFD_SUPPORT_DIRECTDRAW ? "on" : "off") << endl
      << "\tPFD_DIRECT3D_ACCELERATED: " << (flags.PFD_DIRECT3D_ACCELERATED ? "on" : "off") << endl
      << "\tPFD_SUPPORT_COMPOSITION: " << (flags.PFD_SUPPORT_COMPOSITION ? "on" : "off") << endl
      << "\tPFD_DOUBLEBUFFER_DONTCARE: " << (flags.PFD_DOUBLEBUFFER_DONTCARE ? "on" : "off") << endl
      << "\tPFD_STEREO_DONTCARE: " << (flags.PFD_STEREO_DONTCARE ? "on" : "off") << endl;

    s.setf(basefield);
    return s;
}


std::ostream& operator << (std::ostream& s, PFPixelType &type) {
    std::ios_base::fmtflags basefield = s.basefield;

    s << "Pixel format type: " 
      << (type == PFD_TYPE_RGBA ? "PDF_TYPE_RGBA (0x00)" : "PDF_TYPE_COLORINDEX (0x01)") 
      << endl;

    s.setf(basefield);
    return s;
}

std::ostream& operator << (std::ostream& s, PixelFormatDescriptor& pxlFmtDesc) {
    std::ios_base::fmtflags basefield = s.basefield;
    
    s << "EMF Pixel Format Descriptor" << endl
      << "==================================" << endl
      << "nSize:           " << pxlFmtDesc.nSize << endl
      << "nVersion:        " << pxlFmtDesc.nVersion << endl
      << "dwFlags:         " << pxlFmtDesc.dwFlags << endl
      << "iPixelType:      " << (pxlFmtDesc.iPixelType == PFD_TYPE_RGBA
                                    ? "PFD_TYPE_RGBA" 
                                    : "PFD_TYPE_COLORINDEX") << endl
      << "cColorBits:      " << pxlFmtDesc.cColorBits << endl
      << "cRedBits:        " << pxlFmtDesc.cRedBits << endl
      << "cRedShift:       " << pxlFmtDesc.cRedShift << endl
      << "cGreenBits:      " << pxlFmtDesc.cGreenBits << endl
      << "cGreenShift:     " << pxlFmtDesc.cGreenShift << endl
      << "cBlueBits:       " << pxlFmtDesc.cBlueBits << endl
      << "cBlueShift:      " << pxlFmtDesc.cBlueShift << endl
      << "cAlphaBits:      " << pxlFmtDesc.cAlphaBits << endl
      << "cAlphaShift:     " << pxlFmtDesc.cAlphaShift << endl
      << "cAccumBits:      " << pxlFmtDesc.cAccumBits << endl
      << "cAccumRedBits:   " << pxlFmtDesc.cAccumRedBits << endl
      << "cAccumGreenBits: " << pxlFmtDesc.cAccumGreenBits << endl
      << "cAccumBlueBits:  " << pxlFmtDesc.cAccumBlueBits << endl
      << "cAccumAlphaBits: " << pxlFmtDesc.cAccumAlphaBits << endl
      << "cDepthBits:      " << pxlFmtDesc.cDepthBits << endl
      << "cStencilBits:    " << pxlFmtDesc.cStencilBits << endl
      << "cAuxBuffers:     " << pxlFmtDesc.cAuxBuffers << endl
      << "iLayerType:      " << pxlFmtDesc.iLayerType << endl
      << "bReserved:       " << pxlFmtDesc.bReserved << endl
      << "dwLayerMask:     " << pxlFmtDesc.dwLayerMask << endl
      << "dwVisibleMask:   " << pxlFmtDesc.dwVisibleMask << endl
      << "dwDamageMask:    " << pxlFmtDesc.dwDamageMask << endl;

    s.setf(basefield);
    return s;
}
