package org.xiao.testcmake;

import android.app.Application;
import android.content.Context;
import android.widget.Toast;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.lang.ref.WeakReference;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Map;

import dalvik.system.DexClassLoader;

public class MyApp extends Application {
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);

        unpacke(base);
//        1.加载dex
//        try {
//            File fileDir =  this.getFilesDir();
//
//            File dex = new File(fileDir.getAbsolutePath() + "/classes.dex");
//
//            //解密释放dex文件
//            InputStream is = this.getResources().getAssets().open("classes.mp3");
//            FileOutputStream fos = new FileOutputStream(dex);
//            byte[] buffer = new byte[0x1000];
//            while(true) {
//                int bytes = is.read(buffer);
//                if (bytes <= 0)
//                    break;
//                fos.write(buffer, 0, bytes);
//            }
//            fos.close();
//            is.close();
//
//
//            File odexDir = new File(fileDir + "/myodex");
//            if (!odexDir.exists())
//                odexDir.mkdir();
//
//            File libDir = new File(fileDir + "/lib");
//            if (!libDir.exists())
//                libDir.mkdir();
//
//            ClassLoader parent = base.getClassLoader();
//            DexClassLoader clsLoader = new DexClassLoader(dex.getAbsolutePath(),
//                    odexDir.getAbsolutePath(),
//                    libDir.getAbsolutePath(),
//                    parent);
//
//            Class clsActivityThread =  Class.forName("android.app.ActivityThread");
//            Method currentActivityThread = clsActivityThread.getDeclaredMethod("currentActivityThread");
//            Object objActivityThread = currentActivityThread.invoke(null);
//            Field mPackages = clsActivityThread.getDeclaredField("mPackages");
//            mPackages.setAccessible(true);
//            Map<String, WeakReference<Object>> map = (Map<String, WeakReference<Object>>)mPackages.get(objActivityThread);
//            WeakReference<Object> ptr = map.get(getPackageName());
//            Object objLoadApk = ptr.get();
//            Class clsLoadApk =  Class.forName("android.app.LoadedApk");
//            Field mClassLoader = clsLoadApk.getDeclaredField("mClassLoader");
//            mClassLoader.setAccessible(true);
//            mClassLoader.set(objLoadApk, clsLoader);
//        } catch (Exception e) {
//            e.printStackTrace();
//        }

    }

    public native DexClassLoader unpacke(Context base);
}
