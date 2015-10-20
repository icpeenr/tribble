#include "GraphicsDeviceManager.h"
/*
PFNGLGENBUFFERSARBPROC    		glGenBuffersARB    			= NULL;
PFNGLBINDBUFFERARBPROC    		glBindBufferARB    			= NULL;
PFNGLBUFFERDATAARBPROC    		glBufferDataARB    			= NULL;
PFNGLDELETEBUFFERSARBPROC 		glDeleteBuffersARB 			= NULL;
PFNGLBUFFERSUBDATAPROC    		glBufferSubDataARB 			= NULL;
PFNGLACTIVETEXTUREPROC    		glActiveTextureARB 			= NULL;
PFNGLCLIENTACTIVETEXTUREPROC	glClientActiveTextureARB	= NULL;
*/
GraphicsDeviceManager::GraphicsDeviceManager()
{
}

GraphicsDeviceManager::~GraphicsDeviceManager()
{
}

void GraphicsDeviceManager::Initialize()
{
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	/*	
	if(IsExtensionSupported("GL_ARB_vertex_buffer_object"))
	{
		glGenBuffersARB          = (PFNGLGENBUFFERSARBPROC)    		wglGetProcAddress("glGenBuffersARB");
		glBindBufferARB          = (PFNGLBINDBUFFERARBPROC)    		wglGetProcAddress("glBindBufferARB");
		glBufferDataARB          = (PFNGLBUFFERDATAARBPROC)    		wglGetProcAddress("glBufferDataARB");
		glDeleteBuffersARB       = (PFNGLDELETEBUFFERSARBPROC) 		wglGetProcAddress("glDeleteBuffersARB");
		glBufferSubDataARB       = (PFNGLBUFFERSUBDATAPROC)    		wglGetProcAddress("glBufferSubDataARB");
		glActiveTextureARB       = (PFNGLACTIVETEXTUREPROC)    		wglGetProcAddress("glActiveTextureARB");
		glClientActiveTextureARB = (PFNGLCLIENTACTIVETEXTUREPROC)	wglGetProcAddress("glClientActiveTextureARB");
	}

	glGetIntegerv(GL_VIEWPORT, (GLint*)&m_oViewport);
	*/
}

void GraphicsDeviceManager::End()
{
	//glfwSwapBuffers();
}

/*
Viewport GraphicsDeviceManager::GetViewport() const
{
	return m_oViewport;
}


bool GraphicsDeviceManager::IsExtensionSupported(const char* extension)
{
	const unsigned char *pszExtensions = NULL;
	const unsigned char *pszStart;
	unsigned char *pszWhere;
	unsigned char *pszTerminator;

// Extension names should not have spaces
	pszWhere = (unsigned char *) strchr(extension, ' ');
	if(pszWhere || *extension == '\0')
		return false;

// Get Extensions String
	pszExtensions = glGetString(GL_EXTENSIONS);

// Search The Extensions String For An Exact Copy
	pszStart = pszExtensions;

	while(true)
	{
		pszWhere = (unsigned char *) strstr((const char *) pszStart, extension);
		if(!pszWhere)
			break;
		pszTerminator = pszWhere + strlen(extension);
		if(pszWhere == pszStart || *(pszWhere - 1) == ' ')
			if(*pszTerminator == ' ' || *pszTerminator == '\0')
				return true;
			pszStart = pszTerminator;
		}

		return false;
	}
*/
	GraphicsDeviceManager*	GraphicsDeviceManager::GetInstance()
	{
		if(!m_pInstance)
		{
			m_pInstance = new GraphicsDeviceManager();
		}

		return m_pInstance;
	}

	GraphicsDeviceManager*	GraphicsDeviceManager::m_pInstance = NULL;