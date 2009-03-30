//
// CtrlLibraryMetaPanel.h
//
// Copyright (c) Shareaza Development Team, 2002-2009.
// This file is part of SHAREAZA (shareaza.sourceforge.net)
//
// Shareaza is free software; you can redistribute it
// and/or modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// Shareaza is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Shareaza; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#pragma once

#include "CtrlPanel.h"
#include "MetaPanel.h"

class CSchema;
class CLibraryFile;


class CLibraryMetaPanel :
	public CPanelCtrl,
	public CThreadImpl
{
	DECLARE_DYNCREATE(CLibraryMetaPanel)

public:
	CLibraryMetaPanel();
	virtual ~CLibraryMetaPanel();

	virtual void Update();

	BOOL		SetServicePanel(CMetaPanel* pPanel);
	CMetaPanel*	GetServicePanel();

protected:
	int				m_nSelected;
	DWORD			m_nIndex;
	BOOL			m_bNewFile;  // flag used to switch off thread if thumbnail can not be extracted
	CString			m_sName;
	CString			m_sPath;
	CString			m_sFolder;
	CString			m_sType;
	CString			m_sSize;
	int				m_nIcon32;
	int				m_nIcon48;
	int				m_nRating;
	CSchema*		m_pSchema;
	CMetaPanel*		m_pMetadata;
	CMetaPanel*		m_pServiceData;
	CRect			m_rcFolder;
	CRect			m_rcRating;

	CCriticalSection	m_pSection;
	BOOL				m_bExternalData;
	BOOL				m_bDownloadingImage;
	BOOL				m_bForceUpdate;
	CSize				m_szThumb;
	CBitmap				m_bmThumb;
	COLORREF			m_crLight;
	int					m_nThumbSize;
	CString				m_sThumb;

	CLibraryList*	GetViewSelection();

	void	DrawText(CDC* pDC, int nX, int nY, LPCTSTR pszText, RECT* pRect = NULL, int nMaxWidth = -1);
	void	DrawThumbnail(CDC* pDC, CRect& rcClient, CRect& rcWork);
	void	DrawThumbnail(CDC* pDC, CRect& rcThumb);

	void	OnRun();

	afx_msg void OnPaint();
	afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	DECLARE_MESSAGE_MAP()
};
