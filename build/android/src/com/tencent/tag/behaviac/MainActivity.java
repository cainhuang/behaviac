package com.tencent.tag.behaviac;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.content.res.*;

public class MainActivity extends Activity {

    /* load our native library */
    static {
    	System.loadLibrary("behaviac");
        System.loadLibrary("btunittest");
    }
	
    private AssetManager mgr;
    
    /* implementend by btunittest.so */
    private static native void btutmain(AssetManager assetManager);
    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        mgr = getResources().getAssets();
        
        btutmain(mgr);
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }
    
}
