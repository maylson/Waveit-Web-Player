#ifndef __Application_H__
#define __Application_H__

#include <OgreRoot.h>
#include <OgreFrameListener.h>
#include <OgreRenderWindow.h>
#include <OgreSceneManager.h>
#include "WaveitInputManager.h"
#include "WaveitCameraMan.h"

#include <OgreAnimationState.h>

namespace Waveit
{
	class Application : public Ogre::FrameListener
	{
		protected:
			Ogre::RenderWindow*		mRenderWindow;
			Ogre::SceneManager*		mSceneMgr;
			Ogre::Camera*			mCamera;
			Ogre::Viewport*			mViewport;
			CameraMan*				mCameraMan;

			Ogre::AnimationState*	mSinbadAnimState;

		public:
			Application();

			~Application();

			void loadResources();

			void setupContent();

			void cleanupContent();

			bool frameRenderingQueued(const Ogre::FrameEvent& evt);

			bool keyPressed(const KeyCode key);

			bool keyReleased(const KeyCode key);

			bool mouseMoved(const int x, const int y, const int z);

			bool mousePressed(const MouseButtonID id);

			bool mouseReleased(const MouseButtonID id);

			bool mouseScrolled(const int z);
	};

}

#endif

