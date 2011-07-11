#include "WaveitManager.h"

template<> Waveit::Manager* Ogre::Singleton<Waveit::Manager>::ms_Singleton = 0;

namespace Waveit
{
	Manager::Manager()
	{
		mRoot						= 0;
		mRenderWindow				= 0;

		mApp = 0;

		mRunning					= false;
		mTimeSinceLastFrame			= 0;
	}

	Manager::~Manager()
	{

	}

	void Manager::initialise()
	{
		mRunning = this->setup();
		Ogre::Root::getSingletonPtr()->addFrameListener(mApp);
	}

	bool Manager::update()
	{
		//This is very important!
		mRenderWindow->windowMovedOrResized();


		mRoot->renderOneFrame();
		return mRunning;
	}

	void Manager::shutdown()
	{
		mApp->cleanupContent();

		delete mApp;

		if (mRoot)
			OGRE_DELETE mRoot;
	}

	void Manager::setCanvas(const int hwnd, const int width, const int height)
	{
		mCanvasHwnd = hwnd;
		mCanvasWidth = width;
		mCanvasHeight = height;
	}

	void Manager::setResourcePath(const char *path)
	{
		mResourcePath = path;
	}

	Ogre::String Manager::getResourcePath() const
	{
		return mResourcePath;
	}

	void Manager::addResources()
	{
		Ogre::ResourceGroupManager::getSingleton().addResourceLocation(mResourcePath + "SdkTrays.zip",	"Zip", "SdkTrays");
		Ogre::ResourceGroupManager::getSingleton().addResourceLocation(mResourcePath + "Sinbad.zip",	"Zip", "Sinbad");
	}

	Ogre::RenderWindow* Manager::getRenderWindow()
	{
		return mRenderWindow;
	}

 
	bool Manager::setup()
	{
		mRoot = OGRE_NEW Ogre::Root("", "", "");
		mRoot->loadPlugin("RenderSystem_GL");

		Ogre::RenderSystemList rsList = Ogre::Root::getSingleton().getAvailableRenderers();
		Ogre::RenderSystem *selectedRenderSystem = rsList.at(0);;
		mRoot->setRenderSystem(selectedRenderSystem);

		// Initialise Ogre Root;
		mRoot->initialise(false, "", "");

		mParams["vsync"] = "true";
		mParams["externalWindowHandle"] = Ogre::StringConverter::toString(mCanvasHwnd);

		mRenderWindow = mRoot->createRenderWindow("Waveit Web Player", mCanvasWidth, mCanvasHeight, false, &mParams);
		
		addResources();

		mApp = new Application();
		mApp->loadResources();
		mApp->setupContent();

		return true;
	}

	void Manager::requestShutdown(void)
	{
		mRunning = false;
	}

	bool Manager::javaKeyPressed(const KeyCode key)
	{
		return mApp->keyPressed(key);
	}

	bool Manager::javaKeyReleased(const KeyCode key)
	{
		return mApp->keyReleased(key);
	}

	bool Manager::javaMouseMoved(const int x, const int y, const int z)
	{
		return mApp->mouseMoved(x, y, z);
	}

	bool Manager::javaMousePressed(const MouseButtonID id)
	{
		return mApp->mousePressed(id);
	}

	bool Manager::javaMouseReleased(const MouseButtonID id)
	{
		return mApp->mouseReleased(id);
	}

	bool Manager::javaMouseScrolled(const int z)
	{
		return mApp->mouseScrolled(z);
	}
}

