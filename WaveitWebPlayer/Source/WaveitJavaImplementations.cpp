#include "WaveitJavaLauncher.h"
#include "WaveitJavaInputListener.h"


#include "WaveitInputManager.h"
#include "WaveitManager.h"

/*
* Waveit Manager instance;
*/
Waveit::Manager mManager;



JNIEXPORT void JNICALL Java_Launcher_initialise
  (JNIEnv *env, jobject obj)
{
	mManager.initialise();
}

JNIEXPORT jboolean JNICALL Java_Launcher_update
  (JNIEnv *env, jobject obj)
{
	return mManager.update();
}

JNIEXPORT void JNICALL Java_Launcher_shutdown
  (JNIEnv *env, jobject obj)
{
	mManager.shutdown();
}

JNIEXPORT void JNICALL Java_Launcher_setCanvas
  (JNIEnv *env, jobject obj, jint hwnd, jint width, jint height)
{
	mManager.setCanvas(hwnd, width, height);
}

JNIEXPORT void JNICALL Java_Launcher_setResourcePath
  (JNIEnv *env, jobject obj, jstring jStr)
{
	jboolean iscopy;
	const char *mfile = env->GetStringUTFChars(jStr, &iscopy);
	mManager.setResourcePath(mfile);
}




/*
 * Class:     InputListener
 * Method:    sendKeyPressed
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_InputListener_sendKeyPressed
  (JNIEnv *env, jobject obj, jint key)
{
	mManager.javaKeyPressed((Waveit::KeyCode)key);
}

/*
 * Class:     InputListener
 * Method:    sendKeyReleased
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_InputListener_sendKeyReleased
  (JNIEnv *env, jobject obj, jint key)
{
	mManager.javaKeyReleased((Waveit::KeyCode)key);
}

/*
 * Class:     InputListener
 * Method:    sendMouseMoved
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_InputListener_sendMouseMoved
  (JNIEnv *env, jobject obj, jint x, jint y)
{
	mManager.javaMouseMoved(x, y, 0);
}

/*
 * Class:     InputListener
 * Method:    sendMouseScrolled
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_InputListener_sendMouseScrolled
  (JNIEnv *env, jobject obj, jint z)
{
	mManager.javaMouseScrolled(z);
}

/*
 * Class:     InputListener
 * Method:    sendMousePressed
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_InputListener_sendMousePressed
  (JNIEnv *env, jobject obj, jint id)
{
	if (id == 1)
		mManager.javaMousePressed(Waveit::MouseButtonID::MB_Left);
	else
		if (id == 3)
			mManager.javaMousePressed(Waveit::MouseButtonID::MB_Right);
		else
			if (id == 2)
				mManager.javaMousePressed(Waveit::MouseButtonID::MB_Middle);
			else
				mManager.javaMousePressed((Waveit::MouseButtonID)id);
}

/*
 * Class:     InputListener
 * Method:    sendMouseReleased
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_InputListener_sendMouseReleased
  (JNIEnv *env, jobject obj, jint id)
{
	if (id == 1)
		mManager.javaMouseReleased(Waveit::MouseButtonID::MB_Left);
	else
		if (id == 3)
			mManager.javaMouseReleased(Waveit::MouseButtonID::MB_Right);
		else
			if (id == 2)
				mManager.javaMouseReleased(Waveit::MouseButtonID::MB_Middle);
			else
				mManager.javaMouseReleased((Waveit::MouseButtonID)id);
}





