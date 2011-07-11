#include "WaveitApplication.h"
#include <OgreEntity.h>

namespace Waveit
{
	Application::Application()
	{
		mRenderWindow = static_cast<Ogre::RenderWindow*>(Ogre::Root::getSingletonPtr()->getRenderTarget("Waveit Web Player"));
		mSceneMgr = Ogre::Root::getSingleton().createSceneManager(Ogre::ST_GENERIC);
		mSceneMgr->setAmbientLight(Ogre::ColourValue(1.0, 1.0, 1.0));


		// setup default viewport layout and camera
		mCamera = mSceneMgr->createCamera("WaveitCamera");

		mViewport = mRenderWindow->addViewport(mCamera);

		mCameraMan = new CameraMan(mCamera);

		mCamera->setNearClipDistance(1.0f);
		mCamera->setFarClipDistance(1000.0f);
	}

	Application::~Application()
	{


	}

	void Application::loadResources()
	{
		Ogre::ResourceGroupManager::getSingleton().initialiseResourceGroup("SdkTrays");
		Ogre::ResourceGroupManager::getSingleton().initialiseResourceGroup("Sinbad");
	}

	void Application::setupContent()
	{
		mCameraMan->setStyle(CS_ORBIT);
		Ogre::Entity *sinbad = mSceneMgr->createEntity("Sinbad", "Sinbad.mesh");
		mSceneMgr->getRootSceneNode()->attachObject(sinbad);

		Ogre::Entity *sword1 = mSceneMgr->createEntity("SinbadSword1", "Sword.mesh");
		Ogre::Entity *sword2 = mSceneMgr->createEntity("SinbadSword2", "Sword.mesh");
		
		sinbad->attachObjectToBone("Sheath.L", sword1);
		sinbad->attachObjectToBone("Sheath.R", sword2);

		mSinbadAnimState = sinbad->getAnimationState("Dance");
		mSinbadAnimState->setEnabled(true);
	}

	void Application::cleanupContent()
	{

	}
	
	bool Application::frameRenderingQueued(const Ogre::FrameEvent& evt)
	{
		//This is very important too!
		mCamera->setAspectRatio((Ogre::Real)mViewport->getActualWidth() / (Ogre::Real)mViewport->getActualHeight());

		mSinbadAnimState->addTime(evt.timeSinceLastFrame);
		mCameraMan->frameRenderingQueued(evt);

		return true;
	}

	bool Application::keyPressed(const KeyCode key)
	{
		mCameraMan->injectKeyDown(key);
		return true;
	}

	bool Application::keyReleased(const KeyCode key)
	{
		mCameraMan->injectKeyUp(key);
		return true;
	}

	bool Application::mouseMoved(const int x, const int y, const int z)
	{
		mCameraMan->injectMouseMove(x, y, z);
		return true;
	}

	bool Application::mousePressed(const MouseButtonID id)
	{
		mCameraMan->injectMouseDown(id);
		return true;
	}

	bool Application::mouseReleased(const MouseButtonID id)
	{
		mCameraMan->injectMouseUp(id);
		return true;
	}

	bool Application::mouseScrolled(const int z)
	{
		mCameraMan->injectMouseMove(0, 0, z);
		return true;
	}
}
