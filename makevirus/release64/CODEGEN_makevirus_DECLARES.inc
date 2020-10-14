'-----------------------------------------------------------------------------
' 由 VisualFreeBasic 5.2.8 生成的源代码
' 生成时间：2020年05月11日 09时00分40秒
' 更多信息请访问 www.yfvb.com 
'-----------------------------------------------------------------------------

' 这里是全局定义源码，所有type、全局变量、函数定义 都在此处。
#include Once "Afx/CGdiPlus/CGdiPlus.inc"
#include Once "afx\CWindow.inc"
Type FormControlsPro_TYPE '保存控件的私有属性，每个控件都不同，全部在此，各取所需。
   hWndParent As HWND   '父窗口句柄
   nName As String  '名称\1\用来代码中识别对象的名称\Command\
   Index As Long   '控件数组索引，小于零表示非控件数组
   IDC As Long     '
   BigIcon As  HICON     '窗口大图标，主要用来主窗口
   SmallIcon  As  HICON  '窗口小图标
   nText as CWSTR     '
   ControlType as Long  '控件类型，为了画控件  >=100 为虚拟控件  100=LABEL   TEXT=1 Button=2
   nData As String     '数据存放，无特定，控件根据自己需要存放任意数据。
   Style as UInteger   '样式，每个控件都有自己的定义
   TransPer As Long  '透明度\0\窗口透明度，百分比(0--100)，0%不透明 100%全透明\0\
   TransColor As Long =&H197F7F7F  '透明颜色\3\透明颜色，格式：&H01020304  02.03.04为7F时，01值0到30是系统色（25为不使用）其它时候是A通道，GDI+需要 02 04 里值对调 
   MousePointer As Long  '指针\2\鼠标在窗口上的形状\0 - 默认,1 - 后台运行,2 - 标准箭头,3 - 十字光标,4 - 箭头和问号,5 - 文本工字光标,6 - 不可用禁止圈,7 - 移动,8 - 双箭头↙↗,9 - 双箭头↑↓,10 - 双箭头向↖↘,11 - 双箭头←→,12 - 垂直箭头,13 - 沙漏,14 - 手型
   ForeColor As Long =&H197F7F7F '文字色 格式：&H01020304  02.03.04为7F时，01值0到30是系统色（25为不使用）其它时候是A通道，GDI+需要 02 04 里值对调 
   BackColor As Long =&H197F7F7F '背景色 格式：&H01020304  02.03.04为7F时，01值0到30是系统色（25为不使用）其它时候是A通道，GDI+需要 02 04 里值对调 
   hBackBrush As HBRUSH '背景刷子，返回给窗口和控件用
   ForeColorHot As Long =&H197F7F7F  '热点字色 格式：&H01020304  02.03.04为7F时，01值0到30是系统色（25为不使用）其它时候是A通道，GDI+需要 02 04 里值对调 
   BackColorHot As Long =&H197F7F7F' 热点底色 格式：&H01020304  02.03.04为7F时，01值0到30是系统色（25为不使用）其它时候是A通道，GDI+需要 02 04 里值对调 
   nFont As String  '字体\4\用于此对象的文本字体。\微软雅黑,9,0\
   Tag As CWSTR  ' 附加 \ 1 \ 私有自定义文本与控件关联。 \ \ 
   ToolTip As CWSTR  ' 提示 \ 1 \ 一个提示，当鼠标光标悬停在控件时显示它。 \ \ 
   ToolTipBalloon  As Long  ' 气球样式 \ 2 \ 一个气球样式显示工具提示。 \ False \ True, False
   ToolWnd As HWND       '提示窗口句柄，用来销毁
   PasswordChar As Long  '密码文字\1\为编辑控件中键入的每个字符显示一个星号（*）或其它字符。仅适用于单行编辑控件。\\
   nCursor As HCURSOR    '鼠标指针句柄
   nLeft As Long         '返回/设置相对于父窗口的 X 响应DPI数值，为 100%DPI数值（像素）
   nTop As Long          '返回/设置相对于父窗口的 Y 响应DPI数值，为 100%DPI数值（像素）
   nWidth As Long        '返回/设置控件宽度 响应DPI数值，为 100%DPI数值（像素）
   nHeight As Long       '返回/设置控件高度 响应DPI数值，为 100%DPI数值（像素））
   anchor  AS LONG       '控件布局 自动调整方式
   nRight As Long        '控件布局 用，相对于窗口右边距离 响应DPI数值，为 100%DPI数值（像素））
   nBottom As Long       '控件布局 用，相对于窗口底边距离 响应DPI数值，为 100%DPI数值（像素））
   centerX AS LONG       '控件布局 用 中点  响应DPI数值，为 100%DPI数值（像素）
   centerY AS LONG       '控件布局 用
   VrControls As FormControlsPro_TYPE ptr '如果是主窗口带 虚拟控件 ，就是下一个虚拟控件链表指针，直到为 0 表示没了
End Type
Declare Function gFLY_GetFontHandles(mFont As String) As HFONT
Declare Function GetCodeColorGDI(coColor As Long) As Long
Declare Function GetCodeColorGDIplue(coColor As Long) As Long
Declare Function FF_AddTooltip(hWndForm AS HWND, strTooltipText AS wString, bBalloon AS Long, X as Long = 0, Y As Long = 0, W As Long = 0, H As Long = 0) As HWND
Declare Sub FLY_VFB_Layout_hWndForm(hWndForm As HWND) 
Declare Sub FLY_VFB_Layout_Handle(fp As FormControlsPro_TYPE ptr, pWidth AS LONG, pHeight AS LONG, nWidth AS LONG, nHeight AS LONG, ByRef x AS LONG, ByRef y AS LONG, ByRef xWidth AS LONG, ByRef yHeight AS LONG)
#include Once "WinClass\yGDI.inc"
#include Once "WinClass\ClsForm.inc"
#include Once "WinClass\ClsControl.inc"
#include Once "WinClass\ClsVirtualCl.inc"

#include Once "WinClass\ClsCheckBox.inc"

#include Once "WinClass\ClsTextBox.inc"

#include Once "WinClass\ClsLabel.inc"

#include Once "WinClass\clsButton.inc"

#include Once "WinClass\ClsOpButton.inc"


Type mv_Class_Form Extends Class_Form
    Check1 As Class_CheckBox
    Text1 As Class_TextBox
    Text2 As Class_TextBox
    Text3 As Class_TextBox
    Check2 As Class_CheckBox
    Label1 As Class_Label
    Label2 As Class_Label
    Label3 As Class_Label
    Text4 As Class_TextBox
    Command1 As Class_Button
    Text5 As Class_TextBox
    Option1 As Class_Option
    Option2 As Class_Option
   Declare Function Show(hWndParent As .hWnd =HWND_DESKTOP,Modal As Boolean = False ,UserData As Integer = 0) As .hWnd '加载窗口并且显示, 模态显示用True {2.True.False} UserData 是传递给创建事件的参数，不保存数值
End Type
Dim Shared gFLY_FontNames() As String ,gFLY_FontHandles() As HFONT
Dim Shared mv As mv_Class_Form
Declare Function ReplaceASM(TiStr As String, TiFind As String, TiRep As String) As String '[FILE:C:\mlgb\VFB\Projects\makevirus\release64\CODEGEN_makevirus_UTILITY.inc|304]
Declare Function FLY_DoMessagePump(pWindow AS CWindow Ptr,ByVal ShowModalFlag As Long, ByVal hWndForm As HWND, ByVal hWndParent As HWND, ByVal nFormShowState As Long, ByVal IsMDIForm As Long) As HWND
Declare Function mv_FORMPROCEDURE(ByVal hWndForm As HWND, ByVal wMsg As uInteger, ByVal wParam As WPARAM, ByVal lParam As LPARAM) As LResult '[FILE:C:\mlgb\VFB\Projects\makevirus\forms\Form1.frm|-252]
Declare Function mv_CODEPROCEDURE(ByVal hWndControl As HWND, ByVal wMsg As uInteger, ByVal wParam As WPARAM, ByVal lParam As LPARAM) As LRESULT '[FILE:C:\mlgb\VFB\Projects\makevirus\forms\Form1.frm|-41]
Declare Sub mv_Command1_BN_Clicked(hWndForm As hWnd, hWndControl As hWnd) '[FILE:C:\mlgb\VFB\Projects\makevirus\forms\Form1.frm|4]
Declare Sub mv_WM_Create(hWndForm As hWnd,UserData As Integer) '[FILE:C:\mlgb\VFB\Projects\makevirus\forms\Form1.frm|53]
Declare Function FF_PUMPHOOK( uMsg As Msg ) As Long '[FILE:#FF_PumpHook#|0]
Declare Function FF_WINMAIN(ByVal hInstance As HINSTANCE) As Long '[FILE:#FF_WinMain#|0]
Declare Sub FF_WINEND(ByVal hInstance As HINSTANCE) '[FILE:#FF_WinMain#|18]
