#define FFI_LIB "libpdfium.so"
typedef long int ptrdiff_t;
typedef long unsigned int size_t;
typedef int wchar_t;
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
typedef enum {
  FPDF_TEXTRENDERMODE_UNKNOWN = -1,
  FPDF_TEXTRENDERMODE_FILL = 0,
  FPDF_TEXTRENDERMODE_STROKE = 1,
  FPDF_TEXTRENDERMODE_FILL_STROKE = 2,
  FPDF_TEXTRENDERMODE_INVISIBLE = 3,
  FPDF_TEXTRENDERMODE_FILL_CLIP = 4,
  FPDF_TEXTRENDERMODE_STROKE_CLIP = 5,
  FPDF_TEXTRENDERMODE_FILL_STROKE_CLIP = 6,
  FPDF_TEXTRENDERMODE_CLIP = 7,
  FPDF_TEXTRENDERMODE_LAST = FPDF_TEXTRENDERMODE_CLIP,
} FPDF_TEXT_RENDERMODE;
typedef struct fpdf_action_t__* FPDF_ACTION;
typedef struct fpdf_annotation_t__* FPDF_ANNOTATION;
typedef struct fpdf_attachment_t__* FPDF_ATTACHMENT;
typedef struct fpdf_avail_t__* FPDF_AVAIL;
typedef struct fpdf_bitmap_t__* FPDF_BITMAP;
typedef struct fpdf_bookmark_t__* FPDF_BOOKMARK;
typedef struct fpdf_clippath_t__* FPDF_CLIPPATH;
typedef struct fpdf_dest_t__* FPDF_DEST;
typedef struct fpdf_document_t__* FPDF_DOCUMENT;
typedef struct fpdf_font_t__* FPDF_FONT;
typedef struct fpdf_form_handle_t__* FPDF_FORMHANDLE;
typedef const struct fpdf_glyphpath_t__* FPDF_GLYPHPATH;
typedef struct fpdf_javascript_action_t* FPDF_JAVASCRIPT_ACTION;
typedef struct fpdf_link_t__* FPDF_LINK;
typedef struct fpdf_page_t__* FPDF_PAGE;
typedef struct fpdf_pagelink_t__* FPDF_PAGELINK;
typedef struct fpdf_pageobject_t__* FPDF_PAGEOBJECT;
typedef struct fpdf_pageobjectmark_t__* FPDF_PAGEOBJECTMARK;
typedef const struct fpdf_pagerange_t__* FPDF_PAGERANGE;
typedef const struct fpdf_pathsegment_t* FPDF_PATHSEGMENT;
typedef struct fpdf_schhandle_t__* FPDF_SCHHANDLE;
typedef const struct fpdf_signature_t__* FPDF_SIGNATURE;
typedef void* FPDF_SKIA_CANVAS;
typedef struct fpdf_structelement_t__* FPDF_STRUCTELEMENT;
typedef const struct fpdf_structelement_attr_t__* FPDF_STRUCTELEMENT_ATTR;
typedef struct fpdf_structtree_t__* FPDF_STRUCTTREE;
typedef struct fpdf_textpage_t__* FPDF_TEXTPAGE;
typedef struct fpdf_widget_t__* FPDF_WIDGET;
typedef struct fpdf_xobject_t__* FPDF_XOBJECT;
typedef int FPDF_BOOL;
typedef int FPDF_RESULT;
typedef unsigned long FPDF_DWORD;
typedef float FS_FLOAT;
typedef enum _FPDF_DUPLEXTYPE_ {
  DuplexUndefined = 0,
  Simplex,
  DuplexFlipShortEdge,
  DuplexFlipLongEdge
} FPDF_DUPLEXTYPE;
typedef unsigned short FPDF_WCHAR;
typedef const char* FPDF_BYTESTRING;
typedef const FPDF_WCHAR* FPDF_WIDESTRING;
typedef struct FPDF_BSTR_ {
  char* str;
  int len;
} FPDF_BSTR;
typedef const char* FPDF_STRING;
typedef struct _FS_MATRIX_ {
  float a;
  float b;
  float c;
  float d;
  float e;
  float f;
} FS_MATRIX;
typedef struct _FS_RECTF_ {
  float left;
  float top;
  float right;
  float bottom;
} * FS_LPRECTF, FS_RECTF;
typedef const FS_RECTF* FS_LPCRECTF;
typedef struct FS_SIZEF_ {
  float width;
  float height;
} * FS_LPSIZEF, FS_SIZEF;
typedef const FS_SIZEF* FS_LPCSIZEF;
typedef struct FS_POINTF_ {
  float x;
  float y;
} * FS_LPPOINTF, FS_POINTF;
typedef const FS_POINTF* FS_LPCPOINTF;
typedef struct _FS_QUADPOINTSF {
  FS_FLOAT x1;
  FS_FLOAT y1;
  FS_FLOAT x2;
  FS_FLOAT y2;
  FS_FLOAT x3;
  FS_FLOAT y3;
  FS_FLOAT x4;
  FS_FLOAT y4;
} FS_QUADPOINTSF;
typedef int FPDF_ANNOTATION_SUBTYPE;
typedef int FPDF_ANNOT_APPEARANCEMODE;
typedef int FPDF_OBJECT_TYPE;
typedef enum {
  FPDF_RENDERERTYPE_AGG = 0,
  FPDF_RENDERERTYPE_SKIA = 1,
} FPDF_RENDERER_TYPE;
typedef struct FPDF_LIBRARY_CONFIG_ {
  int version;
  const char** m_pUserFontPaths;
  void* m_pIsolate;
  unsigned int m_v8EmbedderSlot;
  void* m_pPlatform;
  FPDF_RENDERER_TYPE m_RendererType;
} FPDF_LIBRARY_CONFIG;
 void
FPDF_InitLibraryWithConfig(const FPDF_LIBRARY_CONFIG* config);
 void FPDF_InitLibrary();
 void FPDF_DestroyLibrary();
 void FPDF_SetSandBoxPolicy(FPDF_DWORD policy,
                                                     FPDF_BOOL enable);
 FPDF_DOCUMENT
FPDF_LoadDocument(FPDF_STRING file_path, FPDF_BYTESTRING password);
 FPDF_DOCUMENT
FPDF_LoadMemDocument(const void* data_buf, int size, FPDF_BYTESTRING password);
 FPDF_DOCUMENT
FPDF_LoadMemDocument64(const void* data_buf,
                       size_t size,
                       FPDF_BYTESTRING password);
typedef struct {
  unsigned long m_FileLen;
  int (*m_GetBlock)(void* param,
                    unsigned long position,
                    unsigned char* pBuf,
                    unsigned long size);
  void* m_Param;
} FPDF_FILEACCESS;
typedef struct FPDF_FILEHANDLER_ {
  void* clientData;
  void (*Release)(void* clientData);
  FPDF_DWORD (*GetSize)(void* clientData);
  FPDF_RESULT (*ReadBlock)(void* clientData,
                           FPDF_DWORD offset,
                           void* buffer,
                           FPDF_DWORD size);
  FPDF_RESULT (*WriteBlock)(void* clientData,
                            FPDF_DWORD offset,
                            const void* buffer,
                            FPDF_DWORD size);
  FPDF_RESULT (*Flush)(void* clientData);
  FPDF_RESULT (*Truncate)(void* clientData, FPDF_DWORD size);
} FPDF_FILEHANDLER;
 FPDF_DOCUMENT
FPDF_LoadCustomDocument(FPDF_FILEACCESS* pFileAccess, FPDF_BYTESTRING password);
 FPDF_BOOL FPDF_GetFileVersion(FPDF_DOCUMENT doc,
                                                        int* fileVersion);
 unsigned long FPDF_GetLastError();
 FPDF_BOOL
FPDF_DocumentHasValidCrossReferenceTable(FPDF_DOCUMENT document);
 unsigned long
FPDF_GetTrailerEnds(FPDF_DOCUMENT document,
                    unsigned int* buffer,
                    unsigned long length);
 unsigned long
FPDF_GetDocPermissions(FPDF_DOCUMENT document);
 unsigned long
FPDF_GetDocUserPermissions(FPDF_DOCUMENT document);
 int
FPDF_GetSecurityHandlerRevision(FPDF_DOCUMENT document);
 int FPDF_GetPageCount(FPDF_DOCUMENT document);
 FPDF_PAGE FPDF_LoadPage(FPDF_DOCUMENT document,
                                                  int page_index);
 float FPDF_GetPageWidthF(FPDF_PAGE page);
 double FPDF_GetPageWidth(FPDF_PAGE page);
 float FPDF_GetPageHeightF(FPDF_PAGE page);
 double FPDF_GetPageHeight(FPDF_PAGE page);
 FPDF_BOOL FPDF_GetPageBoundingBox(FPDF_PAGE page,
                                                            FS_RECTF* rect);
 FPDF_BOOL
FPDF_GetPageSizeByIndexF(FPDF_DOCUMENT document,
                         int page_index,
                         FS_SIZEF* size);
 int FPDF_GetPageSizeByIndex(FPDF_DOCUMENT document,
                                                      int page_index,
                                                      double* width,
                                                      double* height);
typedef struct FPDF_COLORSCHEME_ {
  FPDF_DWORD path_fill_color;
  FPDF_DWORD path_stroke_color;
  FPDF_DWORD text_fill_color;
  FPDF_DWORD text_stroke_color;
} FPDF_COLORSCHEME;
 void FPDF_RenderPageBitmap(FPDF_BITMAP bitmap,
                                                     FPDF_PAGE page,
                                                     int start_x,
                                                     int start_y,
                                                     int size_x,
                                                     int size_y,
                                                     int rotate,
                                                     int flags);
 void
FPDF_RenderPageBitmapWithMatrix(FPDF_BITMAP bitmap,
                                FPDF_PAGE page,
                                const FS_MATRIX* matrix,
                                const FS_RECTF* clipping,
                                int flags);
 void FPDF_ClosePage(FPDF_PAGE page);
 void FPDF_CloseDocument(FPDF_DOCUMENT document);
 FPDF_BOOL FPDF_DeviceToPage(FPDF_PAGE page,
                                                      int start_x,
                                                      int start_y,
                                                      int size_x,
                                                      int size_y,
                                                      int rotate,
                                                      int device_x,
                                                      int device_y,
                                                      double* page_x,
                                                      double* page_y);
 FPDF_BOOL FPDF_PageToDevice(FPDF_PAGE page,
                                                      int start_x,
                                                      int start_y,
                                                      int size_x,
                                                      int size_y,
                                                      int rotate,
                                                      double page_x,
                                                      double page_y,
                                                      int* device_x,
                                                      int* device_y);
 FPDF_BITMAP FPDFBitmap_Create(int width,
                                                        int height,
                                                        int alpha);
 FPDF_BITMAP FPDFBitmap_CreateEx(int width,
                                                          int height,
                                                          int format,
                                                          void* first_scan,
                                                          int stride);
 int FPDFBitmap_GetFormat(FPDF_BITMAP bitmap);
 void FPDFBitmap_FillRect(FPDF_BITMAP bitmap,
                                                   int left,
                                                   int top,
                                                   int width,
                                                   int height,
                                                   FPDF_DWORD color);
 void* FPDFBitmap_GetBuffer(FPDF_BITMAP bitmap);
 int FPDFBitmap_GetWidth(FPDF_BITMAP bitmap);
 int FPDFBitmap_GetHeight(FPDF_BITMAP bitmap);
 int FPDFBitmap_GetStride(FPDF_BITMAP bitmap);
 void FPDFBitmap_Destroy(FPDF_BITMAP bitmap);
 FPDF_BOOL
FPDF_VIEWERREF_GetPrintScaling(FPDF_DOCUMENT document);
 int
FPDF_VIEWERREF_GetNumCopies(FPDF_DOCUMENT document);
 FPDF_PAGERANGE
FPDF_VIEWERREF_GetPrintPageRange(FPDF_DOCUMENT document);
 size_t
FPDF_VIEWERREF_GetPrintPageRangeCount(FPDF_PAGERANGE pagerange);
 int
FPDF_VIEWERREF_GetPrintPageRangeElement(FPDF_PAGERANGE pagerange, size_t index);
 FPDF_DUPLEXTYPE
FPDF_VIEWERREF_GetDuplex(FPDF_DOCUMENT document);
 unsigned long
FPDF_VIEWERREF_GetName(FPDF_DOCUMENT document,
                       FPDF_BYTESTRING key,
                       char* buffer,
                       unsigned long length);
 FPDF_DWORD
FPDF_CountNamedDests(FPDF_DOCUMENT document);
 FPDF_DEST
FPDF_GetNamedDestByName(FPDF_DOCUMENT document, FPDF_BYTESTRING name);
 FPDF_DEST FPDF_GetNamedDest(FPDF_DOCUMENT document,
                                                      int index,
                                                      void* buffer,
                                                      long* buflen);
 int FPDF_GetXFAPacketCount(FPDF_DOCUMENT document);
 unsigned long FPDF_GetXFAPacketName(
    FPDF_DOCUMENT document,
    int index,
    void* buffer,
    unsigned long buflen);
 FPDF_BOOL FPDF_GetXFAPacketContent(
    FPDF_DOCUMENT document,
    int index,
    void* buffer,
    unsigned long buflen,
    unsigned long* out_buflen);
 int FPDFPage_Flatten(FPDF_PAGE page, int nFlag);
typedef struct _IPDF_JsPlatform {
  int version;
  int (*app_alert)(struct _IPDF_JsPlatform* pThis,
                   FPDF_WIDESTRING Msg,
                   FPDF_WIDESTRING Title,
                   int Type,
                   int Icon);
  void (*app_beep)(struct _IPDF_JsPlatform* pThis, int nType);
  int (*app_response)(struct _IPDF_JsPlatform* pThis,
                      FPDF_WIDESTRING Question,
                      FPDF_WIDESTRING Title,
                      FPDF_WIDESTRING Default,
                      FPDF_WIDESTRING cLabel,
                      FPDF_BOOL bPassword,
                      void* response,
                      int length);
  int (*Doc_getFilePath)(struct _IPDF_JsPlatform* pThis,
                         void* filePath,
                         int length);
  void (*Doc_mail)(struct _IPDF_JsPlatform* pThis,
                   void* mailData,
                   int length,
                   FPDF_BOOL bUI,
                   FPDF_WIDESTRING To,
                   FPDF_WIDESTRING Subject,
                   FPDF_WIDESTRING CC,
                   FPDF_WIDESTRING BCC,
                   FPDF_WIDESTRING Msg);
  void (*Doc_print)(struct _IPDF_JsPlatform* pThis,
                    FPDF_BOOL bUI,
                    int nStart,
                    int nEnd,
                    FPDF_BOOL bSilent,
                    FPDF_BOOL bShrinkToFit,
                    FPDF_BOOL bPrintAsImage,
                    FPDF_BOOL bReverse,
                    FPDF_BOOL bAnnotations);
  void (*Doc_submitForm)(struct _IPDF_JsPlatform* pThis,
                         void* formData,
                         int length,
                         FPDF_WIDESTRING URL);
  void (*Doc_gotoPage)(struct _IPDF_JsPlatform* pThis, int nPageNum);
  int (*Field_browse)(struct _IPDF_JsPlatform* pThis,
                      void* filePath,
                      int length);
  void* m_pFormfillinfo;
  void* m_isolate;
  unsigned int m_v8EmbedderSlot;
} IPDF_JSPLATFORM;
typedef void (*TimerCallback)(int idEvent);
typedef struct _FPDF_SYSTEMTIME {
  unsigned short wYear;
  unsigned short wMonth;
  unsigned short wDayOfWeek;
  unsigned short wDay;
  unsigned short wHour;
  unsigned short wMinute;
  unsigned short wSecond;
  unsigned short wMilliseconds;
} FPDF_SYSTEMTIME;
typedef struct _FPDF_FORMFILLINFO {
  int version;
  void (*Release)(struct _FPDF_FORMFILLINFO* pThis);
  void (*FFI_Invalidate)(struct _FPDF_FORMFILLINFO* pThis,
                         FPDF_PAGE page,
                         double left,
                         double top,
                         double right,
                         double bottom);
  void (*FFI_OutputSelectedRect)(struct _FPDF_FORMFILLINFO* pThis,
                                 FPDF_PAGE page,
                                 double left,
                                 double top,
                                 double right,
                                 double bottom);
  void (*FFI_SetCursor)(struct _FPDF_FORMFILLINFO* pThis, int nCursorType);
  int (*FFI_SetTimer)(struct _FPDF_FORMFILLINFO* pThis,
                      int uElapse,
                      TimerCallback lpTimerFunc);
  void (*FFI_KillTimer)(struct _FPDF_FORMFILLINFO* pThis, int nTimerID);
  FPDF_SYSTEMTIME (*FFI_GetLocalTime)(struct _FPDF_FORMFILLINFO* pThis);
  void (*FFI_OnChange)(struct _FPDF_FORMFILLINFO* pThis);
  FPDF_PAGE (*FFI_GetPage)(struct _FPDF_FORMFILLINFO* pThis,
                           FPDF_DOCUMENT document,
                           int nPageIndex);
  FPDF_PAGE (*FFI_GetCurrentPage)(struct _FPDF_FORMFILLINFO* pThis,
                                  FPDF_DOCUMENT document);
  int (*FFI_GetRotation)(struct _FPDF_FORMFILLINFO* pThis, FPDF_PAGE page);
  void (*FFI_ExecuteNamedAction)(struct _FPDF_FORMFILLINFO* pThis,
                                 FPDF_BYTESTRING namedAction);
  void (*FFI_SetTextFieldFocus)(struct _FPDF_FORMFILLINFO* pThis,
                                FPDF_WIDESTRING value,
                                FPDF_DWORD valueLen,
                                FPDF_BOOL is_focus);
  void (*FFI_DoURIAction)(struct _FPDF_FORMFILLINFO* pThis,
                          FPDF_BYTESTRING bsURI);
  void (*FFI_DoGoToAction)(struct _FPDF_FORMFILLINFO* pThis,
                           int nPageIndex,
                           int zoomMode,
                           float* fPosArray,
                           int sizeofArray);
  IPDF_JSPLATFORM* m_pJsPlatform;
  FPDF_BOOL xfa_disabled;
  void (*FFI_DisplayCaret)(struct _FPDF_FORMFILLINFO* pThis,
                           FPDF_PAGE page,
                           FPDF_BOOL bVisible,
                           double left,
                           double top,
                           double right,
                           double bottom);
  int (*FFI_GetCurrentPageIndex)(struct _FPDF_FORMFILLINFO* pThis,
                                 FPDF_DOCUMENT document);
  void (*FFI_SetCurrentPage)(struct _FPDF_FORMFILLINFO* pThis,
                             FPDF_DOCUMENT document,
                             int iCurPage);
  void (*FFI_GotoURL)(struct _FPDF_FORMFILLINFO* pThis,
                      FPDF_DOCUMENT document,
                      FPDF_WIDESTRING wsURL);
  void (*FFI_GetPageViewRect)(struct _FPDF_FORMFILLINFO* pThis,
                              FPDF_PAGE page,
                              double* left,
                              double* top,
                              double* right,
                              double* bottom);
  void (*FFI_PageEvent)(struct _FPDF_FORMFILLINFO* pThis,
                        int page_count,
                        FPDF_DWORD event_type);
  FPDF_BOOL (*FFI_PopupMenu)(struct _FPDF_FORMFILLINFO* pThis,
                             FPDF_PAGE page,
                             FPDF_WIDGET hWidget,
                             int menuFlag,
                             float x,
                             float y);
  FPDF_FILEHANDLER* (*FFI_OpenFile)(struct _FPDF_FORMFILLINFO* pThis,
                                    int fileFlag,
                                    FPDF_WIDESTRING wsURL,
                                    const char* mode);
  void (*FFI_EmailTo)(struct _FPDF_FORMFILLINFO* pThis,
                      FPDF_FILEHANDLER* fileHandler,
                      FPDF_WIDESTRING pTo,
                      FPDF_WIDESTRING pSubject,
                      FPDF_WIDESTRING pCC,
                      FPDF_WIDESTRING pBcc,
                      FPDF_WIDESTRING pMsg);
  void (*FFI_UploadTo)(struct _FPDF_FORMFILLINFO* pThis,
                       FPDF_FILEHANDLER* fileHandler,
                       int fileFlag,
                       FPDF_WIDESTRING uploadTo);
  int (*FFI_GetPlatform)(struct _FPDF_FORMFILLINFO* pThis,
                         void* platform,
                         int length);
  int (*FFI_GetLanguage)(struct _FPDF_FORMFILLINFO* pThis,
                         void* language,
                         int length);
  FPDF_FILEHANDLER* (*FFI_DownloadFromURL)(struct _FPDF_FORMFILLINFO* pThis,
                                           FPDF_WIDESTRING URL);
  FPDF_BOOL (*FFI_PostRequestURL)(struct _FPDF_FORMFILLINFO* pThis,
                                  FPDF_WIDESTRING wsURL,
                                  FPDF_WIDESTRING wsData,
                                  FPDF_WIDESTRING wsContentType,
                                  FPDF_WIDESTRING wsEncode,
                                  FPDF_WIDESTRING wsHeader,
                                  FPDF_BSTR* response);
  FPDF_BOOL (*FFI_PutRequestURL)(struct _FPDF_FORMFILLINFO* pThis,
                                 FPDF_WIDESTRING wsURL,
                                 FPDF_WIDESTRING wsData,
                                 FPDF_WIDESTRING wsEncode);
  void (*FFI_OnFocusChange)(struct _FPDF_FORMFILLINFO* param,
                            FPDF_ANNOTATION annot,
                            int page_index);
  void(*FFI_DoURIActionWithKeyboardModifier)(struct _FPDF_FORMFILLINFO* param,
      FPDF_BYTESTRING uri,
      int modifiers);
} FPDF_FORMFILLINFO;
 FPDF_FORMHANDLE
FPDFDOC_InitFormFillEnvironment(FPDF_DOCUMENT document,
                                FPDF_FORMFILLINFO* formInfo);
 void
FPDFDOC_ExitFormFillEnvironment(FPDF_FORMHANDLE hHandle);
 void FORM_OnAfterLoadPage(FPDF_PAGE page,
                                                    FPDF_FORMHANDLE hHandle);
 void FORM_OnBeforeClosePage(FPDF_PAGE page,
                                                      FPDF_FORMHANDLE hHandle);
 void
FORM_DoDocumentJSAction(FPDF_FORMHANDLE hHandle);
 void
FORM_DoDocumentOpenAction(FPDF_FORMHANDLE hHandle);
 void FORM_DoDocumentAAction(FPDF_FORMHANDLE hHandle,
                                                      int aaType);
 void FORM_DoPageAAction(FPDF_PAGE page,
                                                  FPDF_FORMHANDLE hHandle,
                                                  int aaType);
 FPDF_BOOL FORM_OnMouseMove(FPDF_FORMHANDLE hHandle,
                                                     FPDF_PAGE page,
                                                     int modifier,
                                                     double page_x,
                                                     double page_y);
 FPDF_BOOL FORM_OnMouseWheel(
    FPDF_FORMHANDLE hHandle,
    FPDF_PAGE page,
    int modifier,
    const FS_POINTF* page_coord,
    int delta_x,
    int delta_y);
 FPDF_BOOL FORM_OnFocus(FPDF_FORMHANDLE hHandle,
                                                 FPDF_PAGE page,
                                                 int modifier,
                                                 double page_x,
                                                 double page_y);
 FPDF_BOOL FORM_OnLButtonDown(FPDF_FORMHANDLE hHandle,
                                                       FPDF_PAGE page,
                                                       int modifier,
                                                       double page_x,
                                                       double page_y);
 FPDF_BOOL FORM_OnRButtonDown(FPDF_FORMHANDLE hHandle,
                                                       FPDF_PAGE page,
                                                       int modifier,
                                                       double page_x,
                                                       double page_y);
 FPDF_BOOL FORM_OnLButtonUp(FPDF_FORMHANDLE hHandle,
                                                     FPDF_PAGE page,
                                                     int modifier,
                                                     double page_x,
                                                     double page_y);
 FPDF_BOOL FORM_OnRButtonUp(FPDF_FORMHANDLE hHandle,
                                                     FPDF_PAGE page,
                                                     int modifier,
                                                     double page_x,
                                                     double page_y);
 FPDF_BOOL
FORM_OnLButtonDoubleClick(FPDF_FORMHANDLE hHandle,
                          FPDF_PAGE page,
                          int modifier,
                          double page_x,
                          double page_y);
 FPDF_BOOL FORM_OnKeyDown(FPDF_FORMHANDLE hHandle,
                                                   FPDF_PAGE page,
                                                   int nKeyCode,
                                                   int modifier);
 FPDF_BOOL FORM_OnKeyUp(FPDF_FORMHANDLE hHandle,
                                                 FPDF_PAGE page,
                                                 int nKeyCode,
                                                 int modifier);
 FPDF_BOOL FORM_OnChar(FPDF_FORMHANDLE hHandle,
                                                FPDF_PAGE page,
                                                int nChar,
                                                int modifier);
 unsigned long
FORM_GetFocusedText(FPDF_FORMHANDLE hHandle,
                    FPDF_PAGE page,
                    void* buffer,
                    unsigned long buflen);
 unsigned long
FORM_GetSelectedText(FPDF_FORMHANDLE hHandle,
                     FPDF_PAGE page,
                     void* buffer,
                     unsigned long buflen);
 void
FORM_ReplaceAndKeepSelection(FPDF_FORMHANDLE hHandle,
                             FPDF_PAGE page,
                             FPDF_WIDESTRING wsText);
 void FORM_ReplaceSelection(FPDF_FORMHANDLE hHandle,
                                                     FPDF_PAGE page,
                                                     FPDF_WIDESTRING wsText);
 FPDF_BOOL
FORM_SelectAllText(FPDF_FORMHANDLE hHandle, FPDF_PAGE page);
 FPDF_BOOL FORM_CanUndo(FPDF_FORMHANDLE hHandle,
                                                 FPDF_PAGE page);
 FPDF_BOOL FORM_CanRedo(FPDF_FORMHANDLE hHandle,
                                                 FPDF_PAGE page);
 FPDF_BOOL FORM_Undo(FPDF_FORMHANDLE hHandle,
                                              FPDF_PAGE page);
 FPDF_BOOL FORM_Redo(FPDF_FORMHANDLE hHandle,
                                              FPDF_PAGE page);
 FPDF_BOOL
FORM_ForceToKillFocus(FPDF_FORMHANDLE hHandle);
 FPDF_BOOL
FORM_GetFocusedAnnot(FPDF_FORMHANDLE handle,
                     int* page_index,
                     FPDF_ANNOTATION* annot);
 FPDF_BOOL
FORM_SetFocusedAnnot(FPDF_FORMHANDLE handle, FPDF_ANNOTATION annot);
 int
FPDFPage_HasFormFieldAtPoint(FPDF_FORMHANDLE hHandle,
                             FPDF_PAGE page,
                             double page_x,
                             double page_y);
 int
FPDFPage_FormFieldZOrderAtPoint(FPDF_FORMHANDLE hHandle,
                                FPDF_PAGE page,
                                double page_x,
                                double page_y);
 void
FPDF_SetFormFieldHighlightColor(FPDF_FORMHANDLE hHandle,
                                int fieldType,
                                unsigned long color);
 void
FPDF_SetFormFieldHighlightAlpha(FPDF_FORMHANDLE hHandle, unsigned char alpha);
 void
FPDF_RemoveFormFieldHighlight(FPDF_FORMHANDLE hHandle);
 void FPDF_FFLDraw(FPDF_FORMHANDLE hHandle,
                                            FPDF_BITMAP bitmap,
                                            FPDF_PAGE page,
                                            int start_x,
                                            int start_y,
                                            int size_x,
                                            int size_y,
                                            int rotate,
                                            int flags);
 int FPDF_GetFormType(FPDF_DOCUMENT document);
 FPDF_BOOL
FORM_SetIndexSelected(FPDF_FORMHANDLE hHandle,
                      FPDF_PAGE page,
                      int index,
                      FPDF_BOOL selected);
 FPDF_BOOL
FORM_IsIndexSelected(FPDF_FORMHANDLE hHandle, FPDF_PAGE page, int index);
 FPDF_BOOL FPDF_LoadXFA(FPDF_DOCUMENT document);
typedef enum FPDFANNOT_COLORTYPE {
  FPDFANNOT_COLORTYPE_Color = 0,
  FPDFANNOT_COLORTYPE_InteriorColor
} FPDFANNOT_COLORTYPE;
 FPDF_BOOL
FPDFAnnot_IsSupportedSubtype(FPDF_ANNOTATION_SUBTYPE subtype);
 FPDF_ANNOTATION
FPDFPage_CreateAnnot(FPDF_PAGE page, FPDF_ANNOTATION_SUBTYPE subtype);
 int FPDFPage_GetAnnotCount(FPDF_PAGE page);
 FPDF_ANNOTATION FPDFPage_GetAnnot(FPDF_PAGE page,
                                                            int index);
 int FPDFPage_GetAnnotIndex(FPDF_PAGE page,
                                                     FPDF_ANNOTATION annot);
 void FPDFPage_CloseAnnot(FPDF_ANNOTATION annot);
 FPDF_BOOL FPDFPage_RemoveAnnot(FPDF_PAGE page,
                                                         int index);
 FPDF_ANNOTATION_SUBTYPE
FPDFAnnot_GetSubtype(FPDF_ANNOTATION annot);
 FPDF_BOOL
FPDFAnnot_IsObjectSupportedSubtype(FPDF_ANNOTATION_SUBTYPE subtype);
 FPDF_BOOL
FPDFAnnot_UpdateObject(FPDF_ANNOTATION annot, FPDF_PAGEOBJECT obj);
 int FPDFAnnot_AddInkStroke(FPDF_ANNOTATION annot,
                                                     const FS_POINTF* points,
                                                     size_t point_count);
 FPDF_BOOL
FPDFAnnot_RemoveInkList(FPDF_ANNOTATION annot);
 FPDF_BOOL
FPDFAnnot_AppendObject(FPDF_ANNOTATION annot, FPDF_PAGEOBJECT obj);
 int FPDFAnnot_GetObjectCount(FPDF_ANNOTATION annot);
 FPDF_PAGEOBJECT
FPDFAnnot_GetObject(FPDF_ANNOTATION annot, int index);
 FPDF_BOOL
FPDFAnnot_RemoveObject(FPDF_ANNOTATION annot, int index);
 FPDF_BOOL FPDFAnnot_SetColor(FPDF_ANNOTATION annot,
                                                       FPDFANNOT_COLORTYPE type,
                                                       unsigned int R,
                                                       unsigned int G,
                                                       unsigned int B,
                                                       unsigned int A);
 FPDF_BOOL FPDFAnnot_GetColor(FPDF_ANNOTATION annot,
                                                       FPDFANNOT_COLORTYPE type,
                                                       unsigned int* R,
                                                       unsigned int* G,
                                                       unsigned int* B,
                                                       unsigned int* A);
 FPDF_BOOL
FPDFAnnot_HasAttachmentPoints(FPDF_ANNOTATION annot);
 FPDF_BOOL
FPDFAnnot_SetAttachmentPoints(FPDF_ANNOTATION annot,
                              size_t quad_index,
                              const FS_QUADPOINTSF* quad_points);
 FPDF_BOOL
FPDFAnnot_AppendAttachmentPoints(FPDF_ANNOTATION annot,
                                 const FS_QUADPOINTSF* quad_points);
 size_t
FPDFAnnot_CountAttachmentPoints(FPDF_ANNOTATION annot);
 FPDF_BOOL
FPDFAnnot_GetAttachmentPoints(FPDF_ANNOTATION annot,
                              size_t quad_index,
                              FS_QUADPOINTSF* quad_points);
 FPDF_BOOL FPDFAnnot_SetRect(FPDF_ANNOTATION annot,
                                                      const FS_RECTF* rect);
 FPDF_BOOL FPDFAnnot_GetRect(FPDF_ANNOTATION annot,
                                                      FS_RECTF* rect);
 unsigned long
FPDFAnnot_GetVertices(FPDF_ANNOTATION annot,
                      FS_POINTF* buffer,
                      unsigned long length);
 unsigned long
FPDFAnnot_GetInkListCount(FPDF_ANNOTATION annot);
 unsigned long
FPDFAnnot_GetInkListPath(FPDF_ANNOTATION annot,
                         unsigned long path_index,
                         FS_POINTF* buffer,
                         unsigned long length);
 FPDF_BOOL FPDFAnnot_GetLine(FPDF_ANNOTATION annot,
                                                      FS_POINTF* start,
                                                      FS_POINTF* end);
 FPDF_BOOL FPDFAnnot_SetBorder(FPDF_ANNOTATION annot,
                                                        float horizontal_radius,
                                                        float vertical_radius,
                                                        float border_width);
 FPDF_BOOL
FPDFAnnot_GetBorder(FPDF_ANNOTATION annot,
                    float* horizontal_radius,
                    float* vertical_radius,
                    float* border_width);
 unsigned long
FPDFAnnot_GetFormAdditionalActionJavaScript(FPDF_FORMHANDLE hHandle,
                                            FPDF_ANNOTATION annot,
                                            int event,
                                            FPDF_WCHAR* buffer,
                                            unsigned long buflen);
 FPDF_BOOL FPDFAnnot_HasKey(FPDF_ANNOTATION annot,
                                                     FPDF_BYTESTRING key);
 FPDF_OBJECT_TYPE
FPDFAnnot_GetValueType(FPDF_ANNOTATION annot, FPDF_BYTESTRING key);
 FPDF_BOOL
FPDFAnnot_SetStringValue(FPDF_ANNOTATION annot,
                         FPDF_BYTESTRING key,
                         FPDF_WIDESTRING value);
 unsigned long
FPDFAnnot_GetStringValue(FPDF_ANNOTATION annot,
                         FPDF_BYTESTRING key,
                         FPDF_WCHAR* buffer,
                         unsigned long buflen);
 FPDF_BOOL
FPDFAnnot_GetNumberValue(FPDF_ANNOTATION annot,
                         FPDF_BYTESTRING key,
                         float* value);
 FPDF_BOOL
FPDFAnnot_SetAP(FPDF_ANNOTATION annot,
                FPDF_ANNOT_APPEARANCEMODE appearanceMode,
                FPDF_WIDESTRING value);
 unsigned long
FPDFAnnot_GetAP(FPDF_ANNOTATION annot,
                FPDF_ANNOT_APPEARANCEMODE appearanceMode,
                FPDF_WCHAR* buffer,
                unsigned long buflen);
 FPDF_ANNOTATION
FPDFAnnot_GetLinkedAnnot(FPDF_ANNOTATION annot, FPDF_BYTESTRING key);
 int FPDFAnnot_GetFlags(FPDF_ANNOTATION annot);
 FPDF_BOOL FPDFAnnot_SetFlags(FPDF_ANNOTATION annot,
                                                       int flags);
 int
FPDFAnnot_GetFormFieldFlags(FPDF_FORMHANDLE handle,
                            FPDF_ANNOTATION annot);
 FPDF_ANNOTATION
FPDFAnnot_GetFormFieldAtPoint(FPDF_FORMHANDLE hHandle,
                              FPDF_PAGE page,
                              const FS_POINTF* point);
 unsigned long
FPDFAnnot_GetFormFieldName(FPDF_FORMHANDLE hHandle,
                           FPDF_ANNOTATION annot,
                           FPDF_WCHAR* buffer,
                           unsigned long buflen);
 unsigned long
FPDFAnnot_GetFormFieldAlternateName(FPDF_FORMHANDLE hHandle,
                                    FPDF_ANNOTATION annot,
                                    FPDF_WCHAR* buffer,
                                    unsigned long buflen);
 int
FPDFAnnot_GetFormFieldType(FPDF_FORMHANDLE hHandle, FPDF_ANNOTATION annot);
 unsigned long
FPDFAnnot_GetFormFieldValue(FPDF_FORMHANDLE hHandle,
                            FPDF_ANNOTATION annot,
                            FPDF_WCHAR* buffer,
                            unsigned long buflen);
 int FPDFAnnot_GetOptionCount(FPDF_FORMHANDLE hHandle,
                                                       FPDF_ANNOTATION annot);
 unsigned long
FPDFAnnot_GetOptionLabel(FPDF_FORMHANDLE hHandle,
                         FPDF_ANNOTATION annot,
                         int index,
                         FPDF_WCHAR* buffer,
                         unsigned long buflen);
 FPDF_BOOL
FPDFAnnot_IsOptionSelected(FPDF_FORMHANDLE handle,
                           FPDF_ANNOTATION annot,
                           int index);
 FPDF_BOOL
FPDFAnnot_GetFontSize(FPDF_FORMHANDLE hHandle,
                      FPDF_ANNOTATION annot,
                      float* value);
 FPDF_BOOL FPDFAnnot_IsChecked(FPDF_FORMHANDLE hHandle,
                                                        FPDF_ANNOTATION annot);
 FPDF_BOOL
FPDFAnnot_SetFocusableSubtypes(FPDF_FORMHANDLE hHandle,
                               const FPDF_ANNOTATION_SUBTYPE* subtypes,
                               size_t count);
 int
FPDFAnnot_GetFocusableSubtypesCount(FPDF_FORMHANDLE hHandle);
 FPDF_BOOL
FPDFAnnot_GetFocusableSubtypes(FPDF_FORMHANDLE hHandle,
                               FPDF_ANNOTATION_SUBTYPE* subtypes,
                               size_t count);
 FPDF_LINK FPDFAnnot_GetLink(FPDF_ANNOTATION annot);
 int
FPDFAnnot_GetFormControlCount(FPDF_FORMHANDLE hHandle, FPDF_ANNOTATION annot);
 int
FPDFAnnot_GetFormControlIndex(FPDF_FORMHANDLE hHandle, FPDF_ANNOTATION annot);
 unsigned long
FPDFAnnot_GetFormFieldExportValue(FPDF_FORMHANDLE hHandle,
                                  FPDF_ANNOTATION annot,
                                  FPDF_WCHAR* buffer,
                                  unsigned long buflen);
 FPDF_BOOL FPDFAnnot_SetURI(FPDF_ANNOTATION annot,
                                                     const char* uri);
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void * __timer_t;
typedef long int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
typedef int __sig_atomic_t;
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;
typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;
typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;
typedef unsigned long int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
typedef struct FPDF_IMAGEOBJ_METADATA {
  unsigned int width;
  unsigned int height;
  float horizontal_dpi;
  float vertical_dpi;
  unsigned int bits_per_pixel;
  int colorspace;
  int marked_content_id;
} FPDF_IMAGEOBJ_METADATA;
 FPDF_DOCUMENT FPDF_CreateNewDocument();
 FPDF_PAGE FPDFPage_New(FPDF_DOCUMENT document,
                                                 int page_index,
                                                 double width,
                                                 double height);
 void FPDFPage_Delete(FPDF_DOCUMENT document,
                                               int page_index);
 FPDF_BOOL
FPDF_MovePages(FPDF_DOCUMENT document,
               const int* page_indices,
               unsigned long page_indices_len,
               int dest_page_index);
 int FPDFPage_GetRotation(FPDF_PAGE page);
 void FPDFPage_SetRotation(FPDF_PAGE page, int rotate);
 void
FPDFPage_InsertObject(FPDF_PAGE page, FPDF_PAGEOBJECT page_object);
 FPDF_BOOL
FPDFPage_RemoveObject(FPDF_PAGE page, FPDF_PAGEOBJECT page_object);
 int FPDFPage_CountObjects(FPDF_PAGE page);
 FPDF_PAGEOBJECT FPDFPage_GetObject(FPDF_PAGE page,
                                                             int index);
 FPDF_BOOL FPDFPage_HasTransparency(FPDF_PAGE page);
 FPDF_BOOL FPDFPage_GenerateContent(FPDF_PAGE page);
 void FPDFPageObj_Destroy(FPDF_PAGEOBJECT page_object);
 FPDF_BOOL
FPDFPageObj_HasTransparency(FPDF_PAGEOBJECT page_object);
 int FPDFPageObj_GetType(FPDF_PAGEOBJECT page_object);
 void
FPDFPageObj_Transform(FPDF_PAGEOBJECT page_object,
                      double a,
                      double b,
                      double c,
                      double d,
                      double e,
                      double f);
 FPDF_BOOL
FPDFPageObj_GetMatrix(FPDF_PAGEOBJECT page_object, FS_MATRIX* matrix);
 FPDF_BOOL
FPDFPageObj_SetMatrix(FPDF_PAGEOBJECT page_object, const FS_MATRIX* matrix);
 void FPDFPage_TransformAnnots(FPDF_PAGE page,
                                                        double a,
                                                        double b,
                                                        double c,
                                                        double d,
                                                        double e,
                                                        double f);
 FPDF_PAGEOBJECT
FPDFPageObj_NewImageObj(FPDF_DOCUMENT document);
 int
FPDFPageObj_CountMarks(FPDF_PAGEOBJECT page_object);
 FPDF_PAGEOBJECTMARK
FPDFPageObj_GetMark(FPDF_PAGEOBJECT page_object, unsigned long index);
 FPDF_PAGEOBJECTMARK
FPDFPageObj_AddMark(FPDF_PAGEOBJECT page_object, FPDF_BYTESTRING name);
 FPDF_BOOL
FPDFPageObj_RemoveMark(FPDF_PAGEOBJECT page_object, FPDF_PAGEOBJECTMARK mark);
 FPDF_BOOL
FPDFPageObjMark_GetName(FPDF_PAGEOBJECTMARK mark,
                        void* buffer,
                        unsigned long buflen,
                        unsigned long* out_buflen);
 int
FPDFPageObjMark_CountParams(FPDF_PAGEOBJECTMARK mark);
 FPDF_BOOL
FPDFPageObjMark_GetParamKey(FPDF_PAGEOBJECTMARK mark,
                            unsigned long index,
                            void* buffer,
                            unsigned long buflen,
                            unsigned long* out_buflen);
 FPDF_OBJECT_TYPE
FPDFPageObjMark_GetParamValueType(FPDF_PAGEOBJECTMARK mark,
                                  FPDF_BYTESTRING key);
 FPDF_BOOL
FPDFPageObjMark_GetParamIntValue(FPDF_PAGEOBJECTMARK mark,
                                 FPDF_BYTESTRING key,
                                 int* out_value);
 FPDF_BOOL
FPDFPageObjMark_GetParamStringValue(FPDF_PAGEOBJECTMARK mark,
                                    FPDF_BYTESTRING key,
                                    void* buffer,
                                    unsigned long buflen,
                                    unsigned long* out_buflen);
 FPDF_BOOL
FPDFPageObjMark_GetParamBlobValue(FPDF_PAGEOBJECTMARK mark,
                                  FPDF_BYTESTRING key,
                                  void* buffer,
                                  unsigned long buflen,
                                  unsigned long* out_buflen);
 FPDF_BOOL
FPDFPageObjMark_SetIntParam(FPDF_DOCUMENT document,
                            FPDF_PAGEOBJECT page_object,
                            FPDF_PAGEOBJECTMARK mark,
                            FPDF_BYTESTRING key,
                            int value);
 FPDF_BOOL
FPDFPageObjMark_SetStringParam(FPDF_DOCUMENT document,
                               FPDF_PAGEOBJECT page_object,
                               FPDF_PAGEOBJECTMARK mark,
                               FPDF_BYTESTRING key,
                               FPDF_BYTESTRING value);
 FPDF_BOOL
FPDFPageObjMark_SetBlobParam(FPDF_DOCUMENT document,
                             FPDF_PAGEOBJECT page_object,
                             FPDF_PAGEOBJECTMARK mark,
                             FPDF_BYTESTRING key,
                             void* value,
                             unsigned long value_len);
 FPDF_BOOL
FPDFPageObjMark_RemoveParam(FPDF_PAGEOBJECT page_object,
                            FPDF_PAGEOBJECTMARK mark,
                            FPDF_BYTESTRING key);
 FPDF_BOOL
FPDFImageObj_LoadJpegFile(FPDF_PAGE* pages,
                          int count,
                          FPDF_PAGEOBJECT image_object,
                          FPDF_FILEACCESS* file_access);
 FPDF_BOOL
FPDFImageObj_LoadJpegFileInline(FPDF_PAGE* pages,
                                int count,
                                FPDF_PAGEOBJECT image_object,
                                FPDF_FILEACCESS* file_access);
 FPDF_BOOL
FPDFImageObj_SetMatrix(FPDF_PAGEOBJECT image_object,
                       double a,
                       double b,
                       double c,
                       double d,
                       double e,
                       double f);
 FPDF_BOOL
FPDFImageObj_SetBitmap(FPDF_PAGE* pages,
                       int count,
                       FPDF_PAGEOBJECT image_object,
                       FPDF_BITMAP bitmap);
 FPDF_BITMAP
FPDFImageObj_GetBitmap(FPDF_PAGEOBJECT image_object);
 FPDF_BITMAP
FPDFImageObj_GetRenderedBitmap(FPDF_DOCUMENT document,
                               FPDF_PAGE page,
                               FPDF_PAGEOBJECT image_object);
 unsigned long
FPDFImageObj_GetImageDataDecoded(FPDF_PAGEOBJECT image_object,
                                 void* buffer,
                                 unsigned long buflen);
 unsigned long
FPDFImageObj_GetImageDataRaw(FPDF_PAGEOBJECT image_object,
                             void* buffer,
                             unsigned long buflen);
 int
FPDFImageObj_GetImageFilterCount(FPDF_PAGEOBJECT image_object);
 unsigned long
FPDFImageObj_GetImageFilter(FPDF_PAGEOBJECT image_object,
                            int index,
                            void* buffer,
                            unsigned long buflen);
 FPDF_BOOL
FPDFImageObj_GetImageMetadata(FPDF_PAGEOBJECT image_object,
                              FPDF_PAGE page,
                              FPDF_IMAGEOBJ_METADATA* metadata);
 FPDF_BOOL
FPDFImageObj_GetImagePixelSize(FPDF_PAGEOBJECT image_object,
                               unsigned int* width,
                               unsigned int* height);
 FPDF_PAGEOBJECT FPDFPageObj_CreateNewPath(float x,
                                                                    float y);
 FPDF_PAGEOBJECT FPDFPageObj_CreateNewRect(float x,
                                                                    float y,
                                                                    float w,
                                                                    float h);
 FPDF_BOOL
FPDFPageObj_GetBounds(FPDF_PAGEOBJECT page_object,
                      float* left,
                      float* bottom,
                      float* right,
                      float* top);
 FPDF_BOOL
FPDFPageObj_GetRotatedBounds(FPDF_PAGEOBJECT page_object,
                             FS_QUADPOINTSF* quad_points);
 void
FPDFPageObj_SetBlendMode(FPDF_PAGEOBJECT page_object,
                         FPDF_BYTESTRING blend_mode);
 FPDF_BOOL
FPDFPageObj_SetStrokeColor(FPDF_PAGEOBJECT page_object,
                           unsigned int R,
                           unsigned int G,
                           unsigned int B,
                           unsigned int A);
 FPDF_BOOL
FPDFPageObj_GetStrokeColor(FPDF_PAGEOBJECT page_object,
                           unsigned int* R,
                           unsigned int* G,
                           unsigned int* B,
                           unsigned int* A);
 FPDF_BOOL
FPDFPageObj_SetStrokeWidth(FPDF_PAGEOBJECT page_object, float width);
 FPDF_BOOL
FPDFPageObj_GetStrokeWidth(FPDF_PAGEOBJECT page_object, float* width);
 int
FPDFPageObj_GetLineJoin(FPDF_PAGEOBJECT page_object);
 FPDF_BOOL
FPDFPageObj_SetLineJoin(FPDF_PAGEOBJECT page_object, int line_join);
 int
FPDFPageObj_GetLineCap(FPDF_PAGEOBJECT page_object);
 FPDF_BOOL
FPDFPageObj_SetLineCap(FPDF_PAGEOBJECT page_object, int line_cap);
 FPDF_BOOL
FPDFPageObj_SetFillColor(FPDF_PAGEOBJECT page_object,
                         unsigned int R,
                         unsigned int G,
                         unsigned int B,
                         unsigned int A);
 FPDF_BOOL
FPDFPageObj_GetFillColor(FPDF_PAGEOBJECT page_object,
                         unsigned int* R,
                         unsigned int* G,
                         unsigned int* B,
                         unsigned int* A);
 FPDF_BOOL
FPDFPageObj_GetDashPhase(FPDF_PAGEOBJECT page_object, float* phase);
 FPDF_BOOL
FPDFPageObj_SetDashPhase(FPDF_PAGEOBJECT page_object, float phase);
 int
FPDFPageObj_GetDashCount(FPDF_PAGEOBJECT page_object);
 FPDF_BOOL
FPDFPageObj_GetDashArray(FPDF_PAGEOBJECT page_object,
                         float* dash_array,
                         size_t dash_count);
 FPDF_BOOL
FPDFPageObj_SetDashArray(FPDF_PAGEOBJECT page_object,
                         const float* dash_array,
                         size_t dash_count,
                         float phase);
 int FPDFPath_CountSegments(FPDF_PAGEOBJECT path);
 FPDF_PATHSEGMENT
FPDFPath_GetPathSegment(FPDF_PAGEOBJECT path, int index);
 FPDF_BOOL
FPDFPathSegment_GetPoint(FPDF_PATHSEGMENT segment, float* x, float* y);
 int FPDFPathSegment_GetType(FPDF_PATHSEGMENT segment);
 FPDF_BOOL
FPDFPathSegment_GetClose(FPDF_PATHSEGMENT segment);
 FPDF_BOOL FPDFPath_MoveTo(FPDF_PAGEOBJECT path,
                                                    float x,
                                                    float y);
 FPDF_BOOL FPDFPath_LineTo(FPDF_PAGEOBJECT path,
                                                    float x,
                                                    float y);
 FPDF_BOOL FPDFPath_BezierTo(FPDF_PAGEOBJECT path,
                                                      float x1,
                                                      float y1,
                                                      float x2,
                                                      float y2,
                                                      float x3,
                                                      float y3);
 FPDF_BOOL FPDFPath_Close(FPDF_PAGEOBJECT path);
 FPDF_BOOL FPDFPath_SetDrawMode(FPDF_PAGEOBJECT path,
                                                         int fillmode,
                                                         FPDF_BOOL stroke);
 FPDF_BOOL FPDFPath_GetDrawMode(FPDF_PAGEOBJECT path,
                                                         int* fillmode,
                                                         FPDF_BOOL* stroke);
 FPDF_PAGEOBJECT
FPDFPageObj_NewTextObj(FPDF_DOCUMENT document,
                       FPDF_BYTESTRING font,
                       float font_size);
 FPDF_BOOL
FPDFText_SetText(FPDF_PAGEOBJECT text_object, FPDF_WIDESTRING text);
 FPDF_BOOL
FPDFText_SetCharcodes(FPDF_PAGEOBJECT text_object,
                      const uint32_t* charcodes,
                      size_t count);
 FPDF_FONT FPDFText_LoadFont(FPDF_DOCUMENT document,
                                                      const uint8_t* data,
                                                      uint32_t size,
                                                      int font_type,
                                                      FPDF_BOOL cid);
 FPDF_FONT
FPDFText_LoadStandardFont(FPDF_DOCUMENT document, FPDF_BYTESTRING font);
 FPDF_BOOL
FPDFTextObj_GetFontSize(FPDF_PAGEOBJECT text, float* size);
 void FPDFFont_Close(FPDF_FONT font);
 FPDF_PAGEOBJECT
FPDFPageObj_CreateTextObj(FPDF_DOCUMENT document,
                          FPDF_FONT font,
                          float font_size);
 FPDF_TEXT_RENDERMODE
FPDFTextObj_GetTextRenderMode(FPDF_PAGEOBJECT text);
 FPDF_BOOL
FPDFTextObj_SetTextRenderMode(FPDF_PAGEOBJECT text,
                              FPDF_TEXT_RENDERMODE render_mode);
 unsigned long
FPDFTextObj_GetText(FPDF_PAGEOBJECT text_object,
                    FPDF_TEXTPAGE text_page,
                    FPDF_WCHAR* buffer,
                    unsigned long length);
 FPDF_BITMAP
FPDFTextObj_GetRenderedBitmap(FPDF_DOCUMENT document,
                              FPDF_PAGE page,
                              FPDF_PAGEOBJECT text_object,
                              float scale);
 FPDF_FONT FPDFTextObj_GetFont(FPDF_PAGEOBJECT text);
 unsigned long
FPDFFont_GetFontName(FPDF_FONT font, char* buffer, unsigned long length);
 FPDF_BOOL FPDFFont_GetFontData(FPDF_FONT font,
                                                         uint8_t* buffer,
                                                         size_t buflen,
                                                         size_t* out_buflen);
 int FPDFFont_GetIsEmbedded(FPDF_FONT font);
 int FPDFFont_GetFlags(FPDF_FONT font);
 int FPDFFont_GetWeight(FPDF_FONT font);
 FPDF_BOOL FPDFFont_GetItalicAngle(FPDF_FONT font,
                                                            int* angle);
 FPDF_BOOL FPDFFont_GetAscent(FPDF_FONT font,
                                                       float font_size,
                                                       float* ascent);
 FPDF_BOOL FPDFFont_GetDescent(FPDF_FONT font,
                                                        float font_size,
                                                        float* descent);
 FPDF_BOOL FPDFFont_GetGlyphWidth(FPDF_FONT font,
                                                           uint32_t glyph,
                                                           float font_size,
                                                           float* width);
 FPDF_GLYPHPATH FPDFFont_GetGlyphPath(FPDF_FONT font,
                                                               uint32_t glyph,
                                                               float font_size);
 int
FPDFGlyphPath_CountGlyphSegments(FPDF_GLYPHPATH glyphpath);
 FPDF_PATHSEGMENT
FPDFGlyphPath_GetGlyphPathSegment(FPDF_GLYPHPATH glyphpath, int index);
 int
FPDFFormObj_CountObjects(FPDF_PAGEOBJECT form_object);
 FPDF_PAGEOBJECT
FPDFFormObj_GetObject(FPDF_PAGEOBJECT form_object, unsigned long index);
typedef struct FPDF_FILEWRITE_ {
  int version;
  int (*WriteBlock)(struct FPDF_FILEWRITE_* pThis,
                    const void* pData,
                    unsigned long size);
} FPDF_FILEWRITE;
 FPDF_BOOL FPDF_SaveAsCopy(FPDF_DOCUMENT document,
                                                    FPDF_FILEWRITE* pFileWrite,
                                                    FPDF_DWORD flags);
 FPDF_BOOL
FPDF_SaveWithVersion(FPDF_DOCUMENT document,
                     FPDF_FILEWRITE* pFileWrite,
                     FPDF_DWORD flags,
                     int fileVersion);
