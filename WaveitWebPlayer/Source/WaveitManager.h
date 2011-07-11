#ifndef __Manager_H__
#define __Manager_H__

#include <OgreSingleton.h>
#include <OgreRoot.h>
#include <OgreRenderWindow.h>

#include "WaveitInputManager.h"
#include "WaveitApplication.h"

namespace Waveit
{
	class Manager : public Ogre::Singleton<Manager>
	{
		protected:
			Ogre::Root									*mRoot;
			Ogre::RenderWindow							*mRenderWindow;
			
		protected:
			Application*								mApp;

			bool										mRunning;

			Ogre::NameValuePairList						mParams;

			// Canvas
			unsigned int								mCanvasHwnd;
			int											mCanvasWidth;
			int											mCanvasHeight;

			Ogre::String								mResourcePath;


			unsigned int								mTimeSinceLastFrame;

		protected: // Private methods inherited from Ogre::FrameListener.
			bool frameRenderingQueued(const Ogre::FrameEvent& evt);

		protected:
			/*
			* Setup the application.
			*/
			bool setup();

			void addResources();

		public:
			/*
			* Construtor.
			*/
			Manager();

			/*
			* Destructor.
			*/
			~Manager();

			/**
			* Request shutdown.
			*/
			void requestShutdown(void);

			Ogre::String getResourcePath() const;

			void initialise();
			bool update();
			void shutdown();
			void setCanvas(const int hwnd, const int width, const int height);
			void setResourcePath(const char *path);

			bool javaKeyPressed(const KeyCode key);
			bool javaKeyReleased(const KeyCode key);
			bool javaMouseMoved(const int x, const int y, const int z);
			bool javaMousePressed(const MouseButtonID id);
			bool javaMouseReleased(const MouseButtonID id);
			bool javaMouseScrolled(const int z);

			Ogre::RenderWindow* getRenderWindow();
	};
}


#endif

