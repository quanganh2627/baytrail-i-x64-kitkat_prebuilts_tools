#ifndef _EFILIB_INCLUDE_
#define _EFILIB_INCLUDE_

/*++

Copyright (c) 2000  Intel Corporation

Module Name:

    efilib.h

Abstract:

    EFI library functions



Revision History

--*/

#include "efidebug.h"
#include "efipart.h"
#include "efilibplat.h"
#include "efilink.h"
#include "efirtlib.h"
#include "pci22.h"
#include "libsmbios.h"

//
// Public read-only data in the EFI library
//

extern EFI_SYSTEM_TABLE         *ST;
extern EFI_BOOT_SERVICES        *BS;
extern EFI_RUNTIME_SERVICES     *RT;

extern EFI_GUID DevicePathProtocol;
extern EFI_GUID LoadedImageProtocol;
extern EFI_GUID TextInProtocol;
extern EFI_GUID TextOutProtocol;
extern EFI_GUID BlockIoProtocol;
extern EFI_GUID DiskIoProtocol;
extern EFI_GUID FileSystemProtocol;
extern EFI_GUID LoadFileProtocol;
extern EFI_GUID DeviceIoProtocol;
extern EFI_GUID VariableStoreProtocol;
extern EFI_GUID LegacyBootProtocol;
extern EFI_GUID UnicodeCollationProtocol;
extern EFI_GUID SerialIoProtocol;
extern EFI_GUID VgaClassProtocol;
extern EFI_GUID TextOutSpliterProtocol;
extern EFI_GUID ErrorOutSpliterProtocol;
extern EFI_GUID TextInSpliterProtocol;
extern EFI_GUID SimpleNetworkProtocol;
extern EFI_GUID PxeBaseCodeProtocol;
extern EFI_GUID PxeCallbackProtocol;
extern EFI_GUID NetworkInterfaceIdentifierProtocol;
extern EFI_GUID UiProtocol;
extern EFI_GUID InternalShellProtocol;
extern EFI_GUID PciIoProtocol;

extern EFI_GUID EfiGlobalVariable;
extern EFI_GUID GenericFileInfo;
extern EFI_GUID FileSystemInfo;
extern EFI_GUID FileSystemVolumeLabelInfo;
extern EFI_GUID PcAnsiProtocol;
extern EFI_GUID Vt100Protocol;
extern EFI_GUID NullGuid;
extern EFI_GUID UnknownDevice;

extern EFI_GUID EfiPartTypeSystemPartitionGuid;
extern EFI_GUID EfiPartTypeLegacyMbrGuid;

extern EFI_GUID MpsTableGuid;
extern EFI_GUID AcpiTableGuid;
extern EFI_GUID SMBIOSTableGuid;
extern EFI_GUID SalSystemTableGuid;

//
// EFI Variable strings
//
#define LOAD_OPTION_ACTIVE      0x00000001

#define VarLanguageCodes       L"LangCodes"
#define VarLanguage            L"Lang"
#define VarTimeout             L"Timeout"
#define VarConsoleInp          L"ConIn"
#define VarConsoleOut          L"ConOut"
#define VarErrorOut            L"ErrOut"
#define VarBootOption          L"Boot%04x"
#define VarBootOrder           L"BootOrder"
#define VarBootNext            L"BootNext"
#define VarBootCurrent         L"BootCurrent"
#define VarDriverOption        L"Driver%04x"
#define VarDriverOrder         L"DriverOrder"
#define VarConsoleInpDev       L"ConInDev"
#define VarConsoleOutDev       L"ConOutDev"
#define VarErrorOutDev         L"ErrOutDev"

#define LanguageCodeEnglish    "eng"

extern EFI_DEVICE_PATH RootDevicePath[];
extern EFI_DEVICE_PATH EndDevicePath[];
extern EFI_DEVICE_PATH EndInstanceDevicePath[];

//
// Other public data in the EFI library
//

extern EFI_MEMORY_TYPE PoolAllocationType;

//
// STATIC - Name is internal to the module
// INTERNAL - Name is internal to the component (i.e., directory)
// BOOTSERVCE - Name of a boot service function
//

#define STATIC
#define INTERNAL
#define BOOTSERVICE

typedef enum {
  OTHER = 0x01,
  UNKNOWN = 0x02,
  INTEL_8086 = 0x03,
  INTEL_80286 = 0x04,
  INTEL_386 = 0x05,
  INTEL_486 = 0x06,
  INTEL_8087 = 0x07,
  INTEL_80287 = 0x08,
  INTEL_80387 = 0x09,
  INTEL_80487 = 0x0A,
  INTEL_PENTIUM = 0x0B,
  INTEL_PENTIUM_PRO = 0x0C,
  INTEL_PENTIUM_II = 0x0D,
  INTEL_PENTIUM_MMX = 0x0E,
  INTEL_CELERON = 0x0F,
  INTEL_PENTIUM_IIXEON = 0x10,
  INTEL_PENTIUM_III = 0x11,
  M1 = 0x12,
  M2 = 0x13,
  INTEL_CELERONM = 0x14,
  INTEL_PENTIUM_MT = 0x15,
  AMD_DURON = 0x18,
  K5 = 0x19,
  K6 = 0x1A,
  K6_2 = 0x1B,
  K6_3 = 0x1C,
  AMD_ATHLON = 0x1D,
  AMD_29000 = 0x1E,
  K6_2PLUS = 0x1F,
  POWER_PC = 0x20,
  POWER_PC601 = 0x21,
  POWER_PC603 = 0x22,
  POWER_PC603_PLUS = 0x23,
  POWER_PC604 = 0x24,
  POWER_PC620 = 0x25,
  POWER_PCx704 = 0x26,
  POWER_PC750 = 0x27,
  INTEL_CORE_DUO = 0x28,
  INTEL_CORE_DUOMOBILE = 0x29,
  INTEL_CORE_SOLOMOBILE = 0x2A,
  INTEL_ATOM = 0x2B,
  ALPHA_3 = 0x30,
  ALPHA_21064 = 0x31,
  ALPHA_21066 = 0x32,
  ALPHA_21164 = 0x33,
  ALPHA_21164PC = 0x34,
  ALPHA_21164A = 0x35,
  ALPHA_21264 = 0x36,
  ALPHA_21364 = 0x37,
  AMD_TURIONII_ULTRADUALM = 0x38,
  AMD_TURIONII_DUAL_COREM = 0x39,
  AMD_ATHLONII_DUAL_CORE_M = 0x3A,
  AMD_OPTERON_6100_SERIES = 0x3B,
  AMD_OPTERON_4100_SERIES = 0x3C,
  AMD_OPTERON_6200_SERIES = 0x3D,
  AMD_OPTERON_4200_SERIES = 0x3E,
  MIPS = 0x40,
  MIPSR4000 = 0x41,
  MIPSR4200 = 0x42,
  MIPSR4400 = 0x43,
  MIPSR4600 = 0x44,
  MIPSR10000 = 0x45,
  AMD_CSERIES = 0x46,
  AMD_ESERIES = 0x47,
  AMD_SSERIES = 0x48,
  AMD_GSERIES = 0x49,
  SPARC = 0x50,
  SUPER_SPARC = 0x51,
  MICRO_SPARCII = 0x52,
  MICRO_SPARCIIEP = 0x53,
  ULTRA_SPARC = 0x54,
  ULTRA_SPARCII = 0x55,
  ULTRA_SPARCIIi = 0x56,
  ULTRA_SPARCIII = 0x57,
  ULTRA_SPARCIIIi = 0x58,
  S68040 = 0x60,
  S68xxx = 0x61,
  S68000 = 0x62,
  S68010 = 0x63,
  S68020 = 0x64,
  S68030 = 0x65,
  HOBBIT = 0x70,
  CRUSOE_TM5000 = 0x78,
  CRUSOE_TM3000 = 0x79,
  EFFICEON_TM8000 = 0x7A,
  WEITEK = 0x80,
  ITANIUM = 0x82,
  AMD_ATHLON64 = 0x83,
  AMD_OPTERON = 0x84,
  AMD_SEMPRON = 0x85,
  AMD_TURION_64 = 0x86,
  DUAL_CORE_AMD_OPTERON = 0x87,
  AMD_ATHLON_64X2_DUAL_CORE = 0x88,
  AMD_TURION_64X2_MOBILE = 0x89,
  QUAD_CORE_AMD_OPTERON = 0x8A,
  AMD_OPTERON_3GEN = 0x8B,
  AMD_PHENOM_FxQUADCORE = 0x8C,
  AMD_PHENOM_X4QUADCORE = 0x8D,
  AMD_PHENOM_X2DUALCORE = 0x8E,
  AMD_ATHLONX2DUALCORE = 0x8F,
  PARISC = 0x90,
  PARISC_8500 = 0x91,
  PARISC_8000 = 0x92,
  PARiSC_7300LC = 0x93,
  PARiSC_7200 = 0x94,
  PARISC_7100LC = 0x95,
  PARISC_7100 = 0x96,
  V30 = 0xA0,
  QUADCORE_INTEL_XEON_G_3200SERIES = 0xA1,
  DUALCORE_INTEL_XEON_G_3000SERIES = 0xA2,
  QUADCORE_INTEL_XEON_G_5300SERIES = 0xA3,
  DUALCORE_INTEL_XEON_G_5100SERIES = 0xA4,
  DUALCORE_INTEL_XEON_G_5000SERIES = 0xA5,
  DUALCORE_INTEL_XEON_G_LV = 0xA6,
  DUALCORE_INTEL_XEON_G_ULV = 0xA7,
  DUALCORE_INTEL_XEON_G_7100SERIES = 0xA8,
  QUADCORE_INTEL_XEON_G_5400SERIES = 0xA9,
  QUADCORE_INTEL_XEON_g = 0xAA,
  DUALCORE_INTEL_XEON_G_5200SERIES = 0xAB,
  DUALCORE_INTEL_XEON_G_7200SERIES = 0xAC,
  QUADCORE_INTEL_XEON_G_7300SERIES = 0xAD,
  QUADCORE_INTEL_XEON_G_7400SERIES = 0xAE,
  MULITCORE_INTEL_XEON_G_7400SERIES = 0xAF,
  PENTIUM_III_XEON_g = 0xB0,
  PENTIUM_III_SPEED = 0xB1,
  PENTIUM4 = 0xB2,
  INTELXEON_g = 0xB3,
  AS400 = 0xB4,
  INTELXEON_gMP = 0xB5,
  AMD_ATHLONXP = 0xB6,
  AMD_ATHLONMP = 0xB7,
  INTEL_ITANIUM2 = 0xB8,
  INTEL_PENTIUMM = 0xB9,
  INTEL_CELEROND = 0xBA,
  INTEL_PENTIUMD = 0xBB,
  INTEL_PENTIUMEx = 0xBC,
  INTEL_CORE_SOLO = 0xBD,
  RESERVED = 0xBE,
  INTELCORE2 = 0xBF,
  INTELCORE2_SOLO = 0xC0,
  INTELCORE2_EXTREME = 0xC1,
  INTELCORE2QUAD = 0xC2,
  INTELCORE2_EXTREME_MOBILE = 0xC3,
  INTELCORE2_DUOMOBILE = 0xC4,
  INTELCORE2_SOLOMOBILE = 0xC5,
  INTEL_CORE_I7 = 0xC6,
  DUALCORE_INTEL_CELERON = 0xC7,
  IBM390 = 0xC8,
  G4 = 0xC9,
  G5 = 0xCA,
  G6 = 0xCB,
  Z_ARCH = 0xCC,
  INTEL_COREI5 = 0xCD,
  INTEL_COREI3 = 0xCE,
  VIAC7M = 0xD2,
  VIAC7D = 0xD3,
  VIAC7 = 0xD4,
  VIAEDEN = 0xD5,
  MULTICORE_INTEL_XEON_g = 0xD6,
  DUALCORE_INTEL_XEON_g3_SERIES = 0xD7,
  QUADCORE_INTEL_XEON_g3_SERIES = 0xD8,
  VIANANO = 0xD9,
  DUALCORE_INTELXEON_g5SERIES = 0xDA,
  QUADCORE_INTELXEON_g5SERIES = 0xDB,
  DUALCORE_INTELXEON_g7SERIES = 0xDD,
  QUADCORE_INTELXEON_g7SERIES = 0xDE,
  MULTICORE_INTELXEON_g7SERIES = 0xDF,
  MULTICORE_INTELXEON_g3400SERIES = 0xE0,
  AMD_OPTERON_QUADCORE = 0xE6,
  AMD_PHENOM_TRIPLE_CORE = 0xE7,
  AMD_TURION_ULTRA_DUALCORE_MOBILE = 0xE8,
  AMD_TURION_DUAL_CORE_MOBILE = 0xE9,
  AMD_ATHLON_DUAL_CORE = 0xEA,
  AMD_SEMPRONSI = 0xEB,
  AMD_PHENOMII = 0xEC,
  AMD_ATHLONII = 0xED,
  SIXCORE_AMD_OPTERON_ = 0xEE,
  AMD_SEMPRONM = 0xEF,
  I860 = 0xFA,
  I960 = 0xFB,
  INDICATOR2 = 0xFE,
  RESERVED1 = 0xFF
} processor_family_data;
//
// Prototypes
//

VOID
InitializeLib (
    IN EFI_HANDLE           ImageHandle,
    IN EFI_SYSTEM_TABLE     *SystemTable
    );

VOID
InitializeUnicodeSupport (
    CHAR8 *LangCode
    );

VOID
EFIDebugVariable (
    VOID
    );

VOID
SetCrc (
    IN OUT EFI_TABLE_HEADER *Hdr
    );

VOID
SetCrcAltSize (
    IN UINTN                 Size,
    IN OUT EFI_TABLE_HEADER *Hdr
    );

BOOLEAN
CheckCrc (
    IN UINTN                 MaxSize,
    IN OUT EFI_TABLE_HEADER *Hdr
    );

BOOLEAN
CheckCrcAltSize (
    IN UINTN                 MaxSize,
    IN UINTN                 Size,
    IN OUT EFI_TABLE_HEADER *Hdr
    );

UINT32
CalculateCrc (
    UINT8 *pt,
    UINTN Size
    );

VOID
ZeroMem (
    IN VOID     *Buffer,
    IN UINTN     Size
    );

VOID
SetMem (
    IN VOID     *Buffer,
    IN UINTN    Size,
    IN UINT8    Value    
    );

VOID
CopyMem (
    IN VOID     *Dest,
    IN VOID     *Src,
    IN UINTN    len
    );

INTN
CompareMem (
    IN VOID     *Dest,
    IN VOID     *Src,
    IN UINTN    len
    );

INTN
StrCmp (
    IN CHAR16   *s1,
    IN CHAR16   *s2
    );

INTN
StrnCmp (
    IN CHAR16   *s1,
    IN CHAR16   *s2,
    IN UINTN    len
    );

INTN
StriCmp (
    IN CHAR16   *s1,
    IN CHAR16   *s2
    );

VOID
StrLwr (
    IN CHAR16   *Str
    );

VOID
StrUpr (
    IN CHAR16   *Str
    );

VOID
StrCpy (
    IN CHAR16   *Dest,
    IN CHAR16    *Src
    );

VOID
StrCat (
    IN CHAR16   *Dest,
    IN CHAR16   *Src
    );

UINTN
StrLen (
    IN CHAR16   *s1
    );

UINTN
StrSize (
    IN CHAR16   *s1
    );

CHAR16 *
StrDuplicate (
    IN CHAR16   *Src
    );

UINTN
strlena (
    IN CHAR8    *s1
    );
    
UINTN
strcmpa (
    IN CHAR8    *s1,
    IN CHAR8    *s2
    );

UINTN
strncmpa (
    IN CHAR8    *s1,
    IN CHAR8    *s2,
    IN UINTN    len
    );

UINTN
xtoi (
    CHAR16      *str
    );

UINTN
Atoi (
    CHAR16  *str
    );

BOOLEAN 
MetaMatch (
    IN CHAR16   *String,
    IN CHAR16   *Pattern
    );

BOOLEAN 
MetaiMatch (
    IN CHAR16   *String,
    IN CHAR16   *Pattern
    );

UINT64
LShiftU64 (
    IN UINT64   Operand,
    IN UINTN    Count
    );

UINT64
RShiftU64 (
    IN UINT64   Operand,
    IN UINTN    Count
    );

UINT64
MultU64x32 (
    IN UINT64   Multiplicand,
    IN UINTN    Multiplier
    );

UINT64
DivU64x32 (
    IN UINT64   Dividend,
    IN UINTN    Divisor,
    OUT UINTN   *Remainder OPTIONAL
    );

VOID
InitializeLock (
    IN OUT FLOCK    *Lock,
    IN EFI_TPL  Priority
    );

VOID
AcquireLock (
    IN FLOCK    *Lock
    );

VOID
ReleaseLock (
    IN FLOCK    *Lock
    );


INTN
CompareGuid(
    IN EFI_GUID     *Guid1,
    IN EFI_GUID     *Guid2
    );

VOID *
AllocatePool (
    IN UINTN     Size
    );

VOID *
AllocateZeroPool (
    IN UINTN     Size
    );

VOID *
ReallocatePool (
    IN VOID                 *OldPool,
    IN UINTN                OldSize,
    IN UINTN                NewSize
    );

VOID
FreePool (
    IN VOID     *p
    );


VOID
Output (
    IN CHAR16   *Str
    );

VOID
Input (
    IN CHAR16   *Prompt OPTIONAL,
    OUT CHAR16  *InStr,
    IN UINTN    StrLen
    );

VOID
IInput (
    IN SIMPLE_TEXT_OUTPUT_INTERFACE     *ConOut,
    IN SIMPLE_INPUT_INTERFACE           *ConIn,
    IN CHAR16                           *Prompt OPTIONAL,
    OUT CHAR16                          *InStr,
    IN UINTN                            StrLen
    );

UINTN
Print (
    IN CHAR16   *fmt,
    ...
    );

UINTN
SPrint (
    OUT CHAR16  *Str,
    IN UINTN    StrSize,
    IN CHAR16   *fmt,
    ...
    );

CHAR16 *
PoolPrint (
    IN CHAR16           *fmt,
    ...
    );

typedef struct {
    CHAR16      *str;
    UINTN       len;
    UINTN       maxlen;
} POOL_PRINT;

CHAR16 *
CatPrint (
    IN OUT POOL_PRINT   *Str,
    IN CHAR16           *fmt,
    ...
    );

UINTN
PrintAt (
    IN UINTN    Column,
    IN UINTN    Row,
    IN CHAR16   *fmt,
    ...
    );

UINTN
IPrint (
    IN SIMPLE_TEXT_OUTPUT_INTERFACE    *Out,
    IN CHAR16                          *fmt,
    ...
    );

UINTN
IPrintAt (
    IN SIMPLE_TEXT_OUTPUT_INTERFACE     *Out,
    IN UINTN                            Column,
    IN UINTN                            Row,
    IN CHAR16                           *fmt,
    ...
    );

UINTN
APrint (
    IN CHAR8    *fmt,
    ...
    );

VOID
ValueToHex (
    IN CHAR16   *Buffer,
    IN UINT64   v
    );

VOID
ValueToString (
    IN CHAR16   *Buffer,
    IN BOOLEAN  Comma,
    IN INT64    v
    );

VOID
TimeToString (
    OUT CHAR16      *Buffer,
    IN EFI_TIME     *Time
    );

VOID
GuidToString (
    OUT CHAR16      *Buffer,
    IN EFI_GUID     *Guid
    );

VOID
StatusToString (
    OUT CHAR16      *Buffer,
    EFI_STATUS      Status
    );

VOID
DumpHex (
    IN UINTN        Indent,
    IN UINTN        Offset,
    IN UINTN        DataSize,
    IN VOID         *UserData
    );

BOOLEAN
GrowBuffer(
    IN OUT EFI_STATUS   *Status,
    IN OUT VOID         **Buffer,
    IN UINTN            BufferSize
    );

EFI_MEMORY_DESCRIPTOR *
LibMemoryMap (
    OUT UINTN               *NoEntries,
    OUT UINTN               *MapKey,
    OUT UINTN               *DescriptorSize,
    OUT UINT32              *DescriptorVersion
    );

VOID *
LibGetVariable (
    IN CHAR16               *Name,
    IN EFI_GUID             *VendorGuid
    );

VOID *
LibGetVariableAndSize (
    IN CHAR16               *Name,
    IN EFI_GUID             *VendorGuid,
    OUT UINTN               *VarSize
    );

EFI_STATUS
LibDeleteVariable (
    IN CHAR16   *VarName,
    IN EFI_GUID *VarGuid
    );

EFI_STATUS
LibInsertToTailOfBootOrder (
    IN  UINT16  BootOption,
    IN  BOOLEAN OnlyInsertIfEmpty
    );

EFI_STATUS
LibLocateProtocol (
    IN  EFI_GUID    *ProtocolGuid,
    OUT VOID        **Interface
    );

EFI_STATUS
LibLocateHandle (
    IN EFI_LOCATE_SEARCH_TYPE   SearchType,
    IN EFI_GUID                 *Protocol OPTIONAL,
    IN VOID                     *SearchKey OPTIONAL,
    IN OUT UINTN                *NoHandles,
    OUT EFI_HANDLE              **Buffer
    );

EFI_STATUS
LibLocateHandleByDiskSignature (
    IN UINT8                        MBRType,
    IN UINT8                        SignatureType,
    IN VOID                         *Signature,
    IN OUT UINTN                    *NoHandles,
    OUT EFI_HANDLE                  **Buffer
    );

EFI_STATUS
LibInstallProtocolInterfaces (
    IN OUT EFI_HANDLE       *Handle,
    ...
    );

VOID
LibUninstallProtocolInterfaces (
    IN EFI_HANDLE           Handle,
    ...
    );

EFI_STATUS
LibReinstallProtocolInterfaces (
    IN OUT EFI_HANDLE           *Handle,
    ...
    );

EFI_EVENT
LibCreateProtocolNotifyEvent (
    IN EFI_GUID             *ProtocolGuid,
    IN EFI_TPL              NotifyTpl,
    IN EFI_EVENT_NOTIFY     NotifyFunction,
    IN VOID                 *NotifyContext,
    OUT VOID                *Registration
    );

EFI_STATUS
WaitForSingleEvent (
    IN EFI_EVENT        Event,
    IN UINT64           Timeout OPTIONAL
    );

VOID
WaitForEventWithTimeout (
    IN  EFI_EVENT       Event,
    IN  UINTN           Timeout,
    IN  UINTN           Row,
    IN  UINTN           Column,
    IN  CHAR16          *String,
    IN  EFI_INPUT_KEY   TimeoutKey,
    OUT EFI_INPUT_KEY   *Key
    );

EFI_FILE_HANDLE
LibOpenRoot (
    IN EFI_HANDLE           DeviceHandle
    );

EFI_FILE_INFO *
LibFileInfo (
    IN EFI_FILE_HANDLE      FHand
    );

EFI_FILE_SYSTEM_INFO *
LibFileSystemInfo (
    IN EFI_FILE_HANDLE      FHand
    );

EFI_FILE_SYSTEM_VOLUME_LABEL_INFO *
LibFileSystemVolumeLabelInfo (
    IN EFI_FILE_HANDLE      FHand
    );

BOOLEAN
ValidMBR(
    IN  MASTER_BOOT_RECORD  *Mbr,
    IN  EFI_BLOCK_IO        *BlkIo
    );

BOOLEAN
LibMatchDevicePaths (
    IN  EFI_DEVICE_PATH *Multi,
    IN  EFI_DEVICE_PATH *Single
    );

EFI_DEVICE_PATH *
LibDuplicateDevicePathInstance (
    IN EFI_DEVICE_PATH  *DevPath
    );

EFI_DEVICE_PATH *
DevicePathFromHandle (
    IN EFI_HANDLE           Handle
    );

EFI_DEVICE_PATH *
DevicePathInstance (
    IN OUT EFI_DEVICE_PATH  **DevicePath,
    OUT UINTN               *Size
    );

UINTN
DevicePathInstanceCount (
    IN EFI_DEVICE_PATH      *DevicePath
    );

EFI_DEVICE_PATH *
AppendDevicePath (
    IN EFI_DEVICE_PATH      *Src1,
    IN EFI_DEVICE_PATH      *Src2
    );

EFI_DEVICE_PATH *
AppendDevicePathNode (
    IN EFI_DEVICE_PATH      *Src1,
    IN EFI_DEVICE_PATH      *Src2
    );

EFI_DEVICE_PATH*
AppendDevicePathInstance (
    IN EFI_DEVICE_PATH  *Src,
    IN EFI_DEVICE_PATH  *Instance
    );

EFI_DEVICE_PATH *
FileDevicePath (
    IN EFI_HANDLE           Device  OPTIONAL,
    IN CHAR16               *FileName
    );

UINTN
DevicePathSize (
    IN EFI_DEVICE_PATH      *DevPath
    );

EFI_DEVICE_PATH *
DuplicateDevicePath (
    IN EFI_DEVICE_PATH      *DevPath
    );

EFI_DEVICE_PATH *
UnpackDevicePath (
    IN EFI_DEVICE_PATH      *DevPath
    );

EFI_STATUS
LibDevicePathToInterface (
    IN EFI_GUID             *Protocol,
    IN EFI_DEVICE_PATH      *FilePath,
    OUT VOID                **Interface
    );

CHAR16 *
DevicePathToStr (
    EFI_DEVICE_PATH         *DevPath
    );

//
// BugBug: I need my own include files
//
typedef struct {
    UINT8   Register;
    UINT8   Function;
    UINT8   Device;
    UINT8   Bus;
    UINT32  Reserved;
} EFI_ADDRESS;

typedef union {
    UINT64          Address;
    EFI_ADDRESS     EfiAddress;
} EFI_PCI_ADDRESS_UNION;


EFI_STATUS
PciFindDeviceClass (
    IN  OUT EFI_PCI_ADDRESS_UNION   *Address,
    IN      UINT8                   BaseClass,
    IN      UINT8                   SubClass
    );

EFI_STATUS
PciFindDevice (
    IN  OUT EFI_PCI_ADDRESS_UNION   *DeviceAddress,
    IN      UINT16                  VendorId,
    IN      UINT16                  DeviceId,
    IN OUT  PCI_TYPE00              *Pci
    );

//
// SIMPLE_READ_FILE object used to access files
//

typedef VOID        *SIMPLE_READ_FILE;

EFI_STATUS
OpenSimpleReadFile (
    IN BOOLEAN                  BootPolicy,
    IN VOID                     *SourceBuffer   OPTIONAL,
    IN UINTN                    SourceSize,
    IN OUT EFI_DEVICE_PATH      **FilePath,
    OUT EFI_HANDLE              *DeviceHandle,    
    OUT SIMPLE_READ_FILE        *SimpleReadHandle
    );

EFI_STATUS
ReadSimpleReadFile (
    IN SIMPLE_READ_FILE     SimpleReadHandle,
    IN UINTN                Offset,
    IN OUT UINTN            *ReadSize,
    OUT VOID                *Buffer
    );


VOID
CloseSimpleReadFile (
    IN SIMPLE_READ_FILE     SimpleReadHandle
    );

VOID
InitializeGuid (
    VOID
    );

UINT8
DecimaltoBCD(
    IN  UINT8 DecValue
    );

UINT8
BCDtoDecimal(
    IN  UINT8 BcdValue
    );

EFI_STATUS
LibGetSystemConfigurationTable(
    IN EFI_GUID *TableGuid,
    IN OUT VOID **Table
    );

BOOLEAN
LibIsValidTextGraphics (
    IN  CHAR16  Graphic,   
    OUT CHAR8   *PcAnsi,    OPTIONAL
    OUT CHAR8   *Ascii      OPTIONAL
    );

BOOLEAN
IsValidAscii (
    IN  CHAR16  Ascii
    );

BOOLEAN
IsValidEfiCntlChar (
    IN  CHAR16  c
    );

CHAR16 *
LibGetUiString (
    IN  EFI_HANDLE      Handle,
    IN  UI_STRING_TYPE  StringType,
    IN  ISO_639_2       *LangCode,
    IN  BOOLEAN         ReturnDevicePathStrOnMismatch
    );

CHAR8*
LibGetSmbiosString (
    IN  SMBIOS_STRUCTURE_POINTER    *Smbios,
    IN  UINT16                      StringNumber
    );

EFI_STATUS
LibGetSmbiosSystemGuidAndSerialNumber (
    IN  EFI_GUID    *SystemGuid,
    OUT CHAR8       **SystemSerialNumber
    );


EFI_STATUS
LibGetSmbiosType4 (
    OUT UINT8       *processor_family
    );


EFI_STATUS
InitializeGlobalIoDevice (
        IN  EFI_DEVICE_PATH             *DevicePath,
        IN  EFI_GUID                    *Protocol,
        IN  CHAR8                       *ErrorStr,
        OUT EFI_DEVICE_IO_INTERFACE     **GlobalIoFncs 
        );

UINT32 
ReadPort (
        IN  EFI_DEVICE_IO_INTERFACE     *GlobalIoFncs, 
        IN  EFI_IO_WIDTH                Width,
        IN  UINTN                       Port
        );

UINT32 
WritePort (
        IN  EFI_DEVICE_IO_INTERFACE     *GlobalIoFncs, 
        IN  EFI_IO_WIDTH                Width,
        IN  UINTN                       Port,
        IN  UINTN                       Data
        );

UINT32 
ReadPciConfig (
        IN  EFI_DEVICE_IO_INTERFACE     *GlobalIoFncs, 
        IN  EFI_IO_WIDTH                Width,
        IN  UINTN                       Port
        );

UINT32 
WritePciConfig (
        IN  EFI_DEVICE_IO_INTERFACE     *GlobalIoFncs, 
        IN  EFI_IO_WIDTH                Width,
        IN  UINTN                       Port,
        IN  UINTN                       Data
        );

extern EFI_DEVICE_IO_INTERFACE  *GlobalIoFncs;

#define outp(_Port, _DataByte)  (UINT8)WritePort(GlobalIoFncs,  IO_UINT8,  (UINTN)_Port, (UINTN)_DataByte)
#define inp(_Port)              (UINT8)ReadPort(GlobalIoFncs,   IO_UINT8,  (UINTN)_Port)
#define outpw(_Port, _DataByte) (UINT16)WritePort(GlobalIoFncs, IO_UINT16, (UINTN)_Port, (UINTN)_DataByte)
#define inpw(_Port)             (UINT16)ReadPort(GlobalIoFncs,  IO_UINT16, (UINTN)_Port)
#define outpd(_Port, _DataByte) (UINT32)WritePort(GlobalIoFncs, IO_UINT32, (UINTN)_Port, (UINTN)_DataByte)
#define inpd(_Port)             (UINT32)ReadPort(GlobalIoFncs,  IO_UINT32, (UINTN)_Port)

#define writepci8(_Addr, _DataByte)  (UINT8)WritePciConfig(GlobalIoFncs,  IO_UINT8,  (UINTN)_Addr, (UINTN)_DataByte)
#define readpci8(_Addr)              (UINT8)ReadPciConfig(GlobalIoFncs,   IO_UINT8,  (UINTN)_Addr)
#define writepci16(_Addr, _DataByte) (UINT16)WritePciConfig(GlobalIoFncs, IO_UINT16, (UINTN)_Addr, (UINTN)_DataByte)
#define readpci16(_Addr)             (UINT16)ReadPciConfig(GlobalIoFncs,  IO_UINT16, (UINTN)_Addr)
#define writepci32(_Addr, _DataByte) (UINT32)WritePciConfig(GlobalIoFncs, IO_UINT32, (UINTN)_Addr, (UINTN)_DataByte)
#define readpci32(_Addr)             (UINT32)ReadPciConfig(GlobalIoFncs,  IO_UINT32, (UINTN)_Addr)

#define Pause()             WaitForSingleEvent (ST->ConIn->WaitForKey, 0)
#define Port80(_PostCode)   GlobalIoFncs->Io.Write (GlobalIoFncs, IO_UINT16, (UINT64)0x80, 1, &(_PostCode))

#endif
