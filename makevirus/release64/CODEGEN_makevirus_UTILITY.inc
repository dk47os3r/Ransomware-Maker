'-----------------------------------------------------------------------------
' 由 VisualFreeBasic 5.2.8 生成的源代码
' 生成时间：2020年05月11日 09时00分40秒
' 更多信息请访问 www.yfvb.com 
'-----------------------------------------------------------------------------

Function gFLY_GetFontHandles(mFont As String) As HFONT '由字体字符，返回字体句柄
   Dim As Long i,u=UBound(gFLY_FontNames),aa =-1
   If u > -1 Then
      For i = 0 To u
         If gFLY_FontNames(i) = mFont Then
            Return gFLY_FontHandles(I)
         End If
      Next
   End If
   aa = u + 1
   ReDim Preserve gFLY_FontNames(aa), gFLY_FontHandles(aa)
   gFLY_FontNames(aa) = mFont
   Dim pvv(5) As String, ff as Long, zz as String = mFont
   for i = 0 to 5
      ff = instr(zz, ",")
      if ff = 0 then
         pvv(i) = Trim(zz)
         exit for
      end if
      pvv(i) = Trim(.left(zz, ff -1))
      zz = Mid(zz, ff + 1)
   next
   if valint(pvv(1)) = 0 then pvv(1) = "9"
   if len(pvv(0)) = 0 then pvv(0) = "SimSun" '宋体
   gFLY_FontHandles(aa) = AfxCreateFont(pvv(0), ValInt(pvv(1)), -1, IIf(ValInt(pvv(2)) = 0, FW_NORMAL, FW_BOLD), ValInt(pvv(3)), ValInt(pvv(4)), ValInt(pvv(5)))
   IF gFLY_FontHandles(aa) = 0 then  '创建失败
      aa -= 1
      ReDim Preserve gFLY_FontNames(aa), gFLY_FontHandles(aa)
      Return 0
   End If
   Function = gFLY_FontHandles(aa)
End Function
Function GetCodeColorGDI(coColor As Long) As Long  '把控件特殊颜色值，转换为 GDI 色  ,返回-1 为不使用或默认
  If (&H00FFFFFF And coColor) = &H7F7F7F Then
      Dim f As Long = Cast(UInteger, (&HFF000000 And coColor)) Shr 24
      If f=25 Then  Return -1   '不使用或默认值 
      If f < 31 Then 
          Return GetSysColor(f)  
      End If  
  End If
  Function = (&H00FFFFFF And coColor) '去掉 A 通道
End Function
Function GetCodeColorGDIplue(coColor As Long) As Long  '把控件特殊颜色值，转换为 GDI+ 色  ,返回0 为不使用或默认
  Dim tColor As Long = coColor 
  If (&H00FFFFFF And coColor) = &H7F7F7F Then
      Dim f As Long = Cast(UInteger, (&HFF000000 And coColor)) Shr 24
      If f = 25 Then Return 0  ' 不使用或默认值 
      If f < 31 Then 
          tColor = GetSysColor(f) Or &HFF000000 '增加 A通道，不透明，不然是全透明  
      End If  
  End If 
  '因为保存的是GDI 的颜色，GDI+ 需要调换
  Dim As UInteger c1 =(&H00FF0000 And tColor),c2 = (&H000000FF And tColor) ,c3 =(&HFF00FF00 And tColor)
  c1 Shr= 16
  c2 Shl= 16 
  Function = c1 Or c2 Or c3  
End Function
' =====================================================================================
' 根据Jose Roca的代码
' 为窗口的整个客户区域创建标准工具提示。
' 参数:
' - hwnd = 窗口句柄
' - strTooltipText = 工具提示文本
' - bBalloon = 气球提示 (TRUE or FALSE)
' 返回值:
'   工具提示控件的句柄
' =====================================================================================
Function FF_AddTooltip(hWndForm AS HWND, strTooltipText AS wString, bBalloon AS Long, X as Long = 0, Y As Long = 0, W As Long = 0, H As Long = 0) As HWND
   
   IF hWndForm = 0 Then Exit Function
   
   Dim hwndTT AS HWND
   Dim dwStyle As Long
   
   dwStyle = WS_POPUP OR TTS_NOPREFIX OR TTS_ALWAYSTIP
   IF bBalloon THEN dwStyle = dwStyle OR TTS_BALLOON
   hwndTT = CreateWindowExW(WS_EX_TOPMOST, "tooltips_class32", "", dwStyle, 0, 0, 0, 0, 0, Cast(HMENU, Null), 0, ByVal Cast(LPVOID, Null))
   
   IF hwndTT = 0 THEN Exit Function
   SetWindowPos(hwndTT, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOACTIVATE)

   Dim tti AS TTTOOLINFOW
   tti.cbSize = SIZEOF(tti)
   tti.uFlags = TTF_SUBCLASS
   tti.hwnd = hWndForm
   tti.hinst = GetModuleHandle(BYVAL NULL)
   
   GetClientRect(hWndForm, Varptr(tti.rect))
   tti.rect.Left = x
   tti.rect.top = y
   if w > 0 then tti.rect.Right = x + w
   if h > 0 then tti.rect.bottom = y + h
   '// 字符串的长度不能超过80个字符，包括终止的空值

   tti.lpszText = @strTooltipText
   tti.uId = 0
   SendMessageW hwndTT, TTM_ADDTOOLW, 0, Cast(LPARAM, Varptr(tti))
   Function = hwndTT
   
End Function
Function FLY_DoMessagePump(pWindow AS CWindow Ptr, ByVal ShowModalFlag As Long, ByVal hWndForm As HWND, ByVal hWndParent As HWND, ByVal nFormShowState As Long, ByVal IsMDIForm As Long) As HWND
   '如果这是一个MDI子窗体，那么它不能显示为模态。
   If (GetWindowLongPtr(hWndForm, GWL_EXSTYLE) And WS_EX_MDICHILD) = WS_EX_MDICHILD Then ShowModalFlag = False
   If ShowModalFlag = True Then
      '确定活动控件的顶层窗口
      While (GetWindowLongPtr(hWndParent, GWL_STYLE) And WS_CHILD) <> 0
         hWndParent = GetParent(hWndParent)
         If (GetWindowLongPtr(hWndParent, GWL_EXSTYLE) And WS_EX_MDICHILD) <> 0 Then Exit While
      Wend
      '为父窗体禁用鼠标和键盘输入
      If hWndParent <> 0 Then EnableWindow(hWndParent, False)
      ShowWindow(hWndForm, nFormShowState)
      UpdateWindow(hWndForm)
      '主消息循环：
      Dim uMsg As MSG
      Dim zTempString As zString * MAX_PATH
      Dim pW AS CWindow Ptr, hWndP As HWND
      Do While GetMessage(@uMsg, Null, 0, 0)
         '处理菜单命令的快捷键
         If uMsg.message = WM_QUIT Then Exit Do
         If FF_PUMPHOOK(uMsg) = 0 Then
            hWndP = uMsg.hwnd
            '确定活动控件的顶层窗口
            WHILE (GetWindowLongPtr(hWndP, GWL_STYLE) AND WS_CHILD) <> 0
               hWndP = GetParent(hWndP)
               IF (GetWindowLongPtr(hWndP, GWL_EXSTYLE) AND WS_EX_MDICHILD) <> 0 THEN EXIT WHILE
            WEND
            pW = AfxCWindowPtr(hWndP)
            if pW Then
               if GetMenu(hWndP) = 0 Then pW = 0
            End if
            If pW = 0 OrElse (pW->AccelHandle = 0) OrElse (TranslateAcceleratorW(hWndP, pW->AccelHandle, @uMsg)) = 0 Then
               If IsMDIForm = TRUE Then
                  If TranslateMDISysAccel(hWndP, @uMsg) <> 0 Then Continue Do
               End If
               'GetClassNameA GetFocus, zTempString, MAX_PATH
               'zTempString = UCase(zTempString)
               ''处理在多行文本框中按ESCAPE导致应用程序接收可能导致应用程序终止的WM_CLOSE的奇怪情况。
               ''还允许TAB键移入和移出多行文本框。
               'if zTempString = "EDIT" Or Left(zTempString, 8) = "RICHEDIT" Then
               'IF (GetWindowLongPtr(GetFocus, GWL_STYLE) AND ES_MULTILINE) = ES_MULTILINE THEN
               'If (uMsg.message = WM_KEYDOWN) And (uMsg.wParam = VK_ESCAPE) Then
               'uMsg.message = WM_COMMAND
               'uMsg.wParam = MakeLong(IDCANCEL, 0)
               'uMsg.lParam = 0
               'End if
               'End If
               'End if
               'If (uMsg.message = WM_CHAR) And (uMsg.wParam = 9) Then
               ''允许Tab键从多行文本框中跳出
               'If (GetAsyncKeyState(VK_SHIFT) And &H8000) = 0 Then
               'SetFocus GetNextDlgTabItem(GetParent(uMsg.hWnd), uMsg.hWnd, FALSE)
               'Else
               'SetFocus GetNextDlgTabItem(GetParent(uMsg.hWnd), uMsg.hWnd, TRUE)
               'End If
               'uMsg.message = WM_NULL
               'End If
               
               If IsDialogMessageW(hWndP, @uMsg) = 0 Then
                  TranslateMessage @uMsg
                  DispatchMessage @uMsg
               End If
            End If
         end if
         If IsWindow(hWndForm) = FALSE Then Exit Do ' 如果表单被销毁，则退出模态消息循环（重要）。
      Loop
           
      If hWndParent<>HWND_DESKTOP AndAlso IsWindow(hWndParent) Then
         EnableWindow(hWndParent, True)
         OpenIcon hWndParent
         SetForegroundWindow hWndParent
         SetFocus hWndParent
      End if
      Function = Cast(hWnd, Cast(LONG_PTR, App.ReturnValue))
      App.ReturnValue = 0
   Else
      ShowWindow hWndForm, nFormShowState
      Function = hWndForm
   End If
End Function

Sub FLY_VFB_Layout_hWndForm(hWndForm As HWND) '处理控件布局
   DIM rcParent AS RECT, rcChild AS RECT
   DIM x AS LONG, y AS LONG, xWidth AS LONG, yHeight AS LONG
   GetClientRect(hWndForm, @rcParent)
   rcParent.Right = AfxUnscaleX(rcParent.Right)  ' 为自动响应DPI，全部调整为 100%DPI 时的数值
   rcParent.Bottom = AfxUnscaleY(rcParent.Bottom)
   '真实控件
   Dim zWnd As HWND = GetWindow(hWndForm, GW_CHILD)
   Dim nHDWP As HDWP = BeginDeferWindowPos(1) '同时更新控件位置
   While zWnd
      Dim fp As FormControlsPro_TYPE ptr = GetPropW(zWnd, "FCP_TYPE_PTR")
      If fp <> 0 AndAlso fp->anchor > 0 then
         GetWindowRect(zWnd, @rcChild)
         FLY_VFB_Layout_Handle(fp, rcParent.Right, rcParent.Bottom, AfxUnscaleX(rcChild.Right - rcChild.Left), AfxUnscaleY(rcChild.Bottom - rcChild.Top), x, y, xWidth, yHeight)
         nHDWP = DeferWindowPos(nHDWP, zWnd, 0, AfxscaleX(x), AfxscaleY(y), AfxscaleX(xWidth), AfxscaleY(yHeight), SWP_NOZORDER Or SWP_NOACTIVATE)
      End If
      zWnd = GetWindow(zWnd, GW_HWNDNEXT)
   Wend
   EndDeferWindowPos nHDWP
   '虚拟控件
   Dim fp As FormControlsPro_TYPE ptr = GetPropW(hWndForm, "FCP_TYPE_PTR")
   While fp    '
      if fp->anchor > 0 Then
         FLY_VFB_Layout_Handle(fp, rcParent.Right, rcParent.Bottom, fp->nWidth, fp->nHeight, x, y, xWidth, yHeight)
         fp->nLeft = x
         fp->nTop = y
         fp->nWidth = xWidth
         fp->nHeight = yHeight
      End if
      Dim sfp As FormControlsPro_TYPE ptr = fp->VrControls
      fp = sfp
   Wend
   
End Sub

Sub FLY_VFB_Layout_Handle(fp As FormControlsPro_TYPE ptr, pWidth AS LONG, pHeight AS LONG, nWidth AS LONG, nHeight AS LONG, ByRef x AS LONG, ByRef y AS LONG, ByRef xWidth AS LONG, ByRef yHeight AS LONG)
  '处理控件布局 
   x = 0 : y = 0 : xWidth = 0 : yHeight = 0
   SELECT CASE fp->anchor
      CASE 0 'AFX_ANCHOR_NONE
         x = fp->nLeft
         y = fp->nTop
         xWidth = MAX(pWidth - fp->nLeft - fp->nRight, 0)
         yHeight = nHeight
      CASE 1 'AFX_ANCHOR_WIDTH
         x = fp->nLeft
         y = fp->nTop
         xWidth = MAX(pWidth - fp->nLeft - fp->nRight, 0)
         yHeight = nHeight
      CASE 2 'AFX_ANCHOR_RIGHT
         x = pWidth - nWidth - fp->nRight
         y = fp->nTop
         xWidth = nWidth
         yHeight = nHeight
      CASE 3 'AFX_ANCHOR_CENTER_HORZ
         x = (pWidth \ 2) + fp->centerX
         y = fp->nTop
         xWidth = nWidth
         yHeight = nHeight
      CASE 4 'AFX_ANCHOR_HEIGHT
         x = fp->nLeft
         y = fp->nTop
         xWidth = nWidth
         yHeight = MAX(pHeight - fp->nTop - fp->nBottom, 0)
      CASE 5 'AFX_ANCHOR_HEIGHT_WIDTH
         x = fp->nLeft
         y = fp->nTop
         xWidth = MAX(pWidth - fp->nLeft - fp->nRight, 0)
         yHeight = MAX(pHeight - fp->nTop - fp->nBottom, 0)
      CASE 6 'AFX_ANCHOR_HEIGHT_RIGHT
         x = pWidth - nWidth - fp->nRight
         y = fp->nTop
         xWidth = nWidth
         yHeight = MAX(pHeight - fp->nTop - fp->nBottom, 0)
      CASE 7 'AFX_ANCHOR_BOTTOM
         x = fp->nLeft
         y = pHeight - fp->nBottom - nHeight
         xWidth = nWidth
         yHeight = nHeight
      CASE 8 'AFX_ANCHOR_BOTTOM_WIDTH
         x = fp->nLeft
         y = pHeight - fp->nBottom - nHeight
         xWidth = MAX(pWidth - fp->nLeft - fp->nRight, 0)
         yHeight = nHeight
      CASE 9 'AFX_ANCHOR_BOTTOM_RIGHT
         x = pWidth - nWidth - fp->nRight
         y = pHeight - fp->nBottom - nHeight
         xWidth = nWidth
         yHeight = nHeight
      CASE 10 'AFX_ANCHOR_CENTER_HORZ_BOTTOM
         x = (pWidth \ 2) + fp->centerX
         y = pHeight - fp->nBottom - nHeight
         xWidth = nWidth
         yHeight = nHeight
      CASE 11 'AFX_ANCHOR_CENTER_VERT
         x = fp->nLeft
         y = (pHeight - nHeight) \ 2
         xWidth = nWidth
         yHeight = nHeight
      CASE 12 'AFX_ANCHOR_CENTER_VERT_RIGHT
         x = pWidth - nWidth - fp->nRight
         y = (pHeight - nHeight) \ 2
         xWidth = nWidth
         yHeight = nHeight
      CASE 13 'AFX_ANCHOR_CENTER
         x = (pWidth \ 2) + fp->centerX
         y = (pHeight \ 2) + fp->centerY
         xWidth = nWidth
         yHeight = nHeight
   END SELECT
End Sub





'[FILE:C:\mlgb\VFB\CodeStore\字符处理\ReplaceASM.inc
Function ReplaceASM(TiStr As String, TiFind As String, TiRep As String) As String
   Dim As ZString Ptr iStr,iFind, iRep
   Dim As Integer val0=Len(TiRep)
   
   If TiStr = "" Or TiFind = "" Or TiRep = "" Then
      Function = TiStr
      Exit Function
   EndIf
   
   iStr = StrPtr(TiStr)
   iFind = StrPtr(TiFind)
   iRep = StrPtr(TiRep)
   
   Dim As Integer iSize=Len(TiStr)-Len(TiFind)
   Dim As ZString Ptr dStr=CAllocate(Len(TiStr)*20)
   Dim  As String toto
   
   Asm
      mov esi, [iStr]
      add [iSize], esi
      mov ebx, [iFind]
      inc dword Ptr[iSize]
      mov edi, [dStr]
   End Asm
   Asm Sub esi, 1
      Asm
         jmp Start1
         Start2 : add esi, ecx
         Start1 : add esi, 1
         cmp [iSize], esi
         jle Done
         movzx eax, Byte Ptr[esi]
         cmp al, [ebx]
         je Match
         mov [edi], al
         add edi, 1
         jmp Start1
         Match : mov ecx, -1
         mov edx, ebx
         B1 : add ecx, 1
         movzx eax, Byte Ptr[edx]
         Test eax, eax
         jz Change
         add edx, 1
         cmp [esi + ecx], al
         je B1
         movzx eax, Byte Ptr[esi]
         mov [edi], al
         add edi, 1
         jmp Start1
         Change : mov edx, [iRep]
      End Asm
      saute : Asm Sub ecx, 1
      Asm
         B2 : movzx eax, Byte Ptr[edx]
         Test eax, eax
         jz Start2
         add edx, 1
         mov [edi], al
         add edi, 1
         jmp B2
         Done : mov ecx, -1
         B3 : add ecx, 1
         movzx eax, Byte Ptr[esi + ecx]
         mov [edi + ecx], al
         Test eax, eax
         jnz B3
         'mov eax,[dStr]
         'mov [toto],eax
      End Asm
      toto = *dStr
      Function = toto
      Sleep(1)
      Deallocate dStr
      
   End Function