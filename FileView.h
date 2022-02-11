/* This file is part of IntelliFile application developed by Mihai MOGA.

IntelliFile is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Open
Source Initiative, either version 3 of the License, or any later version.

IntelliFile is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
IntelliFile.  If not, see <http://www.opensource.org/licenses/gpl-3.0.html>*/

#pragma once

#include "MFCListView.h"
#include "FileList.h"

class CMainFrame;

// CFileView view

class CFileView : public CMFCListView
{
	DECLARE_DYNCREATE(CFileView)

public:
	CFileView();           // protected constructor used by dynamic creation
	virtual ~CFileView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
	virtual void OnInitialUpdate();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDblClickEntry(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

public:
	void ResizeListCtrl();
	void DoubleClickEntry(int nIndex);
	BOOL Refresh();
	BOOL ViewFile();
	BOOL EditFile();
	BOOL CopyFile(CFileView* pDestination);
	BOOL MoveFile(CFileView* pDestination);
	BOOL NewFolder(CFileView* pDestination);
	BOOL DeleteFile(CFileView* pDestination);

public:
	BOOL m_bInitialized;
	CMainFrame* m_pMainFrame;
	BOOL m_bIsLeftPane;
	CFileSystem m_pFileSystem;
	BOOL m_bShiftPressed;
	BOOL m_bCtrlPressed;
	BOOL m_bMenuPressed;

	DECLARE_MESSAGE_MAP()
};