package manpro.smart_lobtank;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class atur_suhu extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_atur_suhu);
    }

    @Override
    public void onBackPressed()
    {
        Intent intent = new Intent(atur_suhu.this, MainActivity.class);
        startActivity(intent);
    }
}
