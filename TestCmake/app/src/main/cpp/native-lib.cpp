#include <jni.h>
#include <string>
#include <android/log.h>

#define TAG "native-lib"

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

jobject MyCallStaticObjMehtod(JNIEnv *env,
                             const char* cls,
                             const char* name,
                             const char* sig,...)
{
    //File fileDir = base.getFilesDir();
    jclass jcls = env->FindClass(cls);
    if (env->ExceptionCheck()) {
        LOGE("[-] %s error", cls);
        env->ExceptionDescribe();
        env->ExceptionClear();
        return NULL;
    }
    LOGD("[+] FindClass %s OK jcls=%p", cls, jcls);

    jmethodID method = env->GetStaticMethodID(jcls, name, sig);
    if (env->ExceptionCheck()) {
        LOGE("[-] GetMethodID %s error", name);
        env->ExceptionDescribe();
        env->ExceptionClear();
        return NULL;
    }
    LOGD("[+] GetMethodID %s OK method=%p", name, method);

    va_list args;
    va_start(args, method);
    jobject  result = env->CallStaticObjectMethodV(jcls, method, args);
    va_end(args);

    if (env->ExceptionCheck()) {
        LOGE("[-] CallStaticObjectMethodV %s error", name);
        env->ExceptionDescribe();
        env->ExceptionClear();
        return NULL;
    }
    LOGD("[+] CallStaticObjectMethodV %s OK result=%d", name, result);
    env->DeleteLocalRef(jcls);
    return result;
}

jboolean MyCallBooleanMehtod(JNIEnv *env,
                     const char* cls,
                     const char* name,
                     const char* sig,
                     jobject obj, ...)
{
    //File fileDir = base.getFilesDir();
    jclass jcls = env->FindClass(cls);
    if (env->ExceptionCheck()) {
        LOGE("[-] %s error", cls);
        env->ExceptionDescribe();
        env->ExceptionClear();
        return NULL;
    }
    LOGD("[+] FindClass %s OK jcls=%p", cls, jcls);

    jmethodID method = env->GetMethodID(jcls, name, sig);
    if (env->ExceptionCheck()) {
        LOGE("[-] GetMethodID %s error", name);
        env->ExceptionDescribe();
        env->ExceptionClear();
        return NULL;
    }
    LOGD("[+] GetMethodID %s OK method=%p", name, method);

    va_list args;
    va_start(args, method);
    jboolean  result = env->CallBooleanMethodV(obj, method, args);
    va_end(args);

    if (env->ExceptionCheck()) {
        LOGE("[-] CallBooleanMethodV %s error", name);
        env->ExceptionDescribe();
        env->ExceptionClear();
        return NULL;
    }
    LOGD("[+] CallBooleanMethodV %s OK result=%d", name, result);
    env->DeleteLocalRef(jcls);
    return result;
}

void MyCallVoidMehtod(JNIEnv *env,
                      const char* cls,
                      const char* name,
                      const char* sig,
                      jobject obj, ...)
{
    //File fileDir = base.getFilesDir();
    jclass jcls = env->FindClass(cls);
    if (env->ExceptionCheck()) {
        LOGE("[-] %s error", cls);
        env->ExceptionDescribe();
        env->ExceptionClear();
        return;
    }
    LOGD("[+] FindClass %s OK jcls=%p", cls, jcls);

    jmethodID method = env->GetMethodID(jcls, name, sig);
    if (env->ExceptionCheck()) {
        LOGE("[-] GetMethodID %s error", name);
        env->ExceptionDescribe();
        env->ExceptionClear();
        return;
    }
    LOGD("[+] GetMethodID %s OK method=%p", name, method);

    va_list args;
    va_start(args, method);
    env->CallVoidMethodV(obj, method, args);
    va_end(args);

    if (env->ExceptionCheck()) {
        LOGE("[-] CallVoidMethodV %s error", name);
        env->ExceptionDescribe();
        env->ExceptionClear();
        return;
    }
    LOGD("[+] CallVoidMethodV %s OK", name);
    env->DeleteLocalRef(jcls);
}

jobject MyCallObjectMehtod(JNIEnv *env,
                           const char* cls,
                           const char* name,
                           const char* sig,
                           jobject obj, ...)
{
    //File fileDir = base.getFilesDir();
    jclass jcls = env->FindClass(cls);
    if (env->ExceptionCheck()) {
        LOGE("[-] %s error", cls);
        env->ExceptionDescribe();
        env->ExceptionClear();
        return NULL;
    }
    LOGD("[+] FindClass %s OK jcls=%p", cls, jcls);

    jmethodID method = env->GetMethodID(jcls, name, sig);
    if (env->ExceptionCheck()) {
        LOGE("[-] GetMethodID %s error", name);
        env->ExceptionDescribe();
        env->ExceptionClear();
        return NULL;
    }
    LOGD("[+] GetMethodID %s OK method=%p", name, method);

    va_list args;
    va_start(args, method);
    jobject  result = env->CallObjectMethodV(obj, method, args);
    va_end(args);

    if (env->ExceptionCheck()) {
        LOGE("[-] CallObjectMethod %s error", name);
        env->ExceptionDescribe();
        env->ExceptionClear();
        return NULL;
    }
    LOGD("[+] CallObjectMethod %s OK result=%p", name, result);
    env->DeleteLocalRef(jcls);
    return result;
}

jint MyCallIntMehtod(JNIEnv *env,
                     const char* cls,
                     const char* name,
                     const char* sig,
                     jobject obj, ...)
{
    //File fileDir = base.getFilesDir();
    jclass jcls = env->FindClass(cls);
    if (env->ExceptionCheck()) {
        LOGE("[-] %s error", cls);
        env->ExceptionDescribe();
        env->ExceptionClear();
        return NULL;
    }
    LOGD("[+] FindClass %s OK jcls=%p", cls, jcls);

    jmethodID method = env->GetMethodID(jcls, name, sig);
    if (env->ExceptionCheck()) {
        LOGE("[-] GetMethodID %s error", name);
        env->ExceptionDescribe();
        env->ExceptionClear();
        return NULL;
    }
    LOGD("[+] GetMethodID %s OK method=%p", name, method);

    va_list args;
    va_start(args, method);
    jint  result = env->CallIntMethodV(obj, method, args);
    va_end(args);

    if (env->ExceptionCheck()) {
        LOGE("[-] CallIntMethodV %s error", name);
        env->ExceptionDescribe();
        env->ExceptionClear();
        return NULL;
    }
    LOGD("[+] CallIntMethodV %s OK result=%d", name, result);
    env->DeleteLocalRef(jcls);
    return result;
}

jobject MyNewObject(JNIEnv *env,
                    const char* cls,
                    const char* name,
                    const char* sig,
                    ...)
{
    jclass jcls = env->FindClass(cls);
    if (env->ExceptionCheck()) {
        LOGE("[-] %s error", cls);
        env->ExceptionDescribe();
        env->ExceptionClear();
        return NULL;
    }
    LOGD("[+] FindClass %s OK jcls=%p", cls, jcls);

    jmethodID method = env->GetMethodID(jcls, name, sig);
    if (env->ExceptionCheck()) {
        LOGE("[-] GetMethodID %s error", name);
        env->ExceptionDescribe();
        env->ExceptionClear();
        return NULL;
    }
    LOGD("[+] GetMethodID %s OK method=%p", name, method);

    va_list args;
    va_start(args, method);
    jobject  result = env->NewObjectV(jcls, method, args);
    va_end(args);

    if (env->ExceptionCheck()) {
        LOGE("[-] NewObject %s error", name);
        env->ExceptionDescribe();
        env->ExceptionClear();
        return NULL;
    }
    LOGD("[+] NewObject %s OK result=%p", name, result);
    env->DeleteLocalRef(jcls);
    return result;
}


extern "C"
JNIEXPORT jobject JNICALL
Java_org_xiao_testcmake_MyApp_unpacke(JNIEnv *env, jobject thiz, jobject base) {
    // TODO: implement unpacke()
    LOGD("[+] unpack_init begin");

    jobject  objFile = MyCallObjectMehtod(env,
                                          "android/content/Context",
                                          "getFilesDir",
                                          "()Ljava/io/File;",
                                          base);

    jstring  objPath = (jstring)MyCallObjectMehtod(env,
                                                   "java/io/File",
                                                   "getAbsolutePath",
                                                   "()Ljava/lang/String;",
                                                   objFile);

    jstring s1 = env->NewStringUTF("/classes.dex");
    jstring  dex_path = (jstring)MyCallObjectMehtod(env,
                                              "java/lang/String",
                                              "concat",
                                              "(Ljava/lang/String;)Ljava/lang/String;",
                                               objPath, s1);

    //File dex = new File(fileDir.getAbsolutePath() + "/classes.dex");
    jobject  objDex =  MyNewObject(env, "java/io/File", "<init>", "(Ljava/lang/String;)V", dex_path);

//    //解密释放dex文件
//    InputStream is = base.getResources().getAssets().open("dest.mp3");
    jobject  objRes = MyCallObjectMehtod(env,
                                         "android/content/Context",
                                         "getResources",
                                         "()Landroid/content/res/Resources;",
                                         base);
    jobject  objAssetManager =  MyCallObjectMehtod(env,
                                                   "android/content/res/Resources",
                                                   "getAssets",
                                                   "()Landroid/content/res/AssetManager;",
                                                   objRes);

    jstring s3 = env->NewStringUTF("classes.mp3");
    jobject objInputStream =  MyCallObjectMehtod(env,
                                                 "android/content/res/AssetManager",
                                                 "open",
                                                 "(Ljava/lang/String;)Ljava/io/InputStream;",
                                                 objAssetManager, s3);

    //    FileOutputStream fos = new FileOutputStream(dex);
    jobject objFileOutputStream = MyNewObject(env, "java/io/FileOutputStream", "<init>", "(Ljava/io/File;)V", objDex);


    //byte[] buffer = new byte[0x1000];
    jobject objBuffer = env->NewByteArray(0x1000);

    while(true) {
        // int bytes = is.read(buffer);
        jint bytes =  MyCallIntMehtod(env, "java/io/InputStream", "read", "([B)I", objInputStream, objBuffer);
        if (bytes <= 0)
            break;

        //fos.write(buffer, 0, bytes);
        MyCallVoidMehtod(env, "java/io/FileOutputStream", "write", "([BII)V",
                         objFileOutputStream, objBuffer, 0, bytes);

    }

    //fos.close();
    //is.close();
    MyCallVoidMehtod(env, "java/io/FileOutputStream", "close", "()V", objFileOutputStream);
    MyCallVoidMehtod(env, "java/io/InputStream", "close", "()V", objInputStream);


//    File odexDir = new File(fileDir.getAbsolutePath() + "/myodex");

    jstring s4 = env->NewStringUTF("/myodex");
    jstring odex_path = (jstring)MyCallObjectMehtod(env,
                                             "java/lang/String",
                                             "concat",
                                             "(Ljava/lang/String;)Ljava/lang/String;",
                                             objPath, s4);
    jobject  odexDir =  MyNewObject(env, "java/io/File", "<init>", "(Ljava/lang/String;)V", odex_path);
    //    if (!odexDir.exists())
    //        odexDir.mkdir();
    jboolean result = MyCallBooleanMehtod(env,"java/io/File","exists","()Z",odexDir);
    if(result != JNI_TRUE){
        MyCallBooleanMehtod(env,"java/io/File","mkdir","()Z",odexDir);
    }
    LOGD("[+] odexDir end");

    //File libDir = new File(fileDir + "/lib");
    jstring s5 = env->NewStringUTF("/lib");
    jstring lib_path = (jstring)MyCallObjectMehtod(env,
                                             "java/lang/String",
                                             "concat",
                                             "(Ljava/lang/String;)Ljava/lang/String;",
                                             objPath, s5);
    jobject  libDir =  MyNewObject(env, "java/io/File", "<init>", "(Ljava/lang/String;)V", lib_path);
    LOGD("[+] libDir end");
    //if (!libDir.exists())
    //    libDir.mkdir();
    result = MyCallBooleanMehtod(env,"java/io/File","exists","()Z",libDir);
    if(result != JNI_TRUE){
        MyCallBooleanMehtod(env,"java/io/File","mkdir","()Z",libDir);
    }

//    ClassLoader parent = base.getClassLoader();
//    android.content
    jobject prarnt = MyCallObjectMehtod(env,"android/content/Context","getClassLoader","()Ljava/lang/ClassLoader;",base);
    LOGD("[+] prarnt end");
//    DexClassLoader clsLoader = new DexClassLoader(dex.getAbsolutePath(),
//                                                  odexDir.getAbsolutePath(),
//                                                  libDir.getAbsolutePath(),
//                                                  parent);

    jobject clsLoader = MyNewObject(env, "dalvik/system/DexClassLoader", "<init>",
                                                                 "(Ljava/lang/String;"
                                                                 "Ljava/lang/String;"
                                                                 "Ljava/lang/String;"
                                                                 "Ljava/lang/ClassLoader;)"
                                                                 "V", dex_path,odex_path,lib_path,prarnt);

    LOGD("[+] clsLoader end");

//    //Class clsActivityThread =  Class.forName("android.app.ActivityThread");
    jclass clsActivityThread = env->FindClass("android/app/ActivityThread");
    LOGD("clsActivityThread = %p", clsActivityThread);

//    //Method currentActivityThread = clsActivityThread.getDeclaredMethod("currentActivityThread");
    jmethodID  currentActivityThread = env->GetStaticMethodID(clsActivityThread,
                                                              "currentActivityThread",
                                                              "()Landroid/app/ActivityThread;");
    LOGD("currentActivityThread = %p", currentActivityThread);

    //Object objActivityThread = currentActivityThread.invoke(null);
    jobject objActivityThread = env->CallStaticObjectMethod(clsActivityThread,currentActivityThread);
    LOGD("objActivityThread = %p", objActivityThread);

    //Field mPackages = clsActivityThread.getDeclaredField("mPackages");
    jfieldID mPackages = env->GetFieldID(clsActivityThread, "mPackages", "Landroid/util/ArrayMap;");
    LOGD("mPackages = %p", mPackages);

    //Map<String, WeakReference<Object>> map = (Map<String, WeakReference<Object>>)mPackages.get(objActivityThread);
    jobject objArrayMap =  env->GetObjectField(objActivityThread, mPackages);

    //WeakReference<Object> ptr = map.get(getPackageName());
    jobject packageName = MyCallObjectMehtod(env, "android/content/Context", "getPackageName","()Ljava/lang/String;", base);
    jobject ptr = MyCallObjectMehtod(env, "java/util/Map", "get",
                                    "(Ljava/lang/Object;)Ljava/lang/Object;", objArrayMap, packageName);

    //Object objLoadApk = ptr.get();
    jobject  objLoadApk = MyCallObjectMehtod(env, "java/lang/ref/WeakReference", "get",
                                             "()Ljava/lang/Object;", ptr);

    //Class clsLoadApk =  Class.forName("android.app.LoadedApk");
    jclass clsLoadApk = env->FindClass("android/app/LoadedApk");
    LOGD("clsLoadApk=%p", clsLoadApk);

    //Field mClassLoader = clsLoadApk.getDeclaredField("mClassLoader");
    jfieldID mClassLoader = env->GetFieldID(clsLoadApk,"mClassLoader","Ljava/lang/ClassLoader;");

    LOGD("mClassLoader=%p", mClassLoader);
    //mClassLoader.set(objLoadApk, clsLoader);
    env->SetObjectField(objLoadApk,mClassLoader,clsLoader);

    return clsLoader;
    LOGD("[+] unpack_init end");
}