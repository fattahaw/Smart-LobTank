package manpro.smart_lobtank;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class cek_ph extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_cek_ph);

        Button setting_ph = findViewById(R.id.buttonSetpH);

        setting_ph.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // Menampilkan screen pesan
                Intent i = new Intent(getApplicationContext(), atur_ph.class);
                startActivity(i);
            }
        });
    }
}
