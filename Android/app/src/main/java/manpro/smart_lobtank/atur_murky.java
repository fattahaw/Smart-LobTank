package manpro.smart_lobtank;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class atur_murky extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_atur_murky);
    }


    @Override
    public void onBackPressed()
    {
        Intent intent = new Intent(atur_murky.this, MainActivity.class);
        startActivity(intent);
    }

}
