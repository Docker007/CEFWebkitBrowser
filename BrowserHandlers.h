#pragma once
#include "stdafx.h"
#include <list>

#include "include/cef_base.h"
#include "include/cef_browser.h"


class CCefClientHandler : public CefClient,public CefDisplayHandler,public CefLifeSpanHandler,public CefLoadHandler,public CefRequestHandler
{
public:
	CCefClientHandler();
	~CCefClientHandler();

	// CefClient methods:
	virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() override;

	virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override;
	
	virtual CefRefPtr<CefLoadHandler> GetLoadHandler() override;

	virtual CefRefPtr<CefRequestHandler> GetRequestHandler() override;

	// CefDisplayHandler methods:
	virtual void OnTitleChange(CefRefPtr<CefBrowser> browser,const CefString& title) override;

	// CefLifeSpanHandler methods:
	virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) override;
	//virtual bool DoClose(CefRefPtr<CefBrowser> browser) override;
	virtual bool DoClose(CefRefPtr<CefBrowser> browser) override;


	// �ͷ�browser����
	virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) override;

	virtual void OnLoadStart(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame) override;
	virtual void OnLoadEnd(CefRefPtr<CefBrowser> browser,CefRefPtr<CefFrame> frame,int httpStatusCode) override;
	// CefLoadHandler methods:
	virtual void OnLoadError(CefRefPtr<CefBrowser> browser,CefRefPtr<CefFrame> frame,ErrorCode errorCode,const CefString& errorText,const CefString& failedUrl) override;

	virtual bool OnBeforePopup(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		const CefString& target_url,
		const CefString& target_frame_name,
		CefLifeSpanHandler::WindowOpenDisposition target_disposition,
		bool user_gesture,
		const CefPopupFeatures& popupFeatures,
		CefWindowInfo& windowInfo,
		CefRefPtr<CefClient>& client,
		CefBrowserSettings& settings,
		bool* no_javascript_access) override;

	CefRefPtr<CefBrowser> GetBrowser();
	void CloseHostBrowser(bool force_close) ;

public:
	CefRefPtr<CefBrowser> browser_;
	std::wstring strCurURL_;//���ص�ǰҳ��url
	HWND hWnd_; //������Ϣ�ľ��
	CefString strTitle_; //��ַ����
	static int nBrowerReferenceCount_;
private:
	// Include the default reference counting implementation.
	IMPLEMENT_REFCOUNTING(CCefClientHandler);
	//IMPLEMENT_LOCKING(CCefClientHandler);
};

