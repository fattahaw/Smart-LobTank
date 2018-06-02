package manpro.smart_lobtank;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class kekeruhan_air extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_kekeruhan_air);

        Button setting_murky = findViewById(R.id.buttonSetKeruh);

        setting_murky.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // Menampilkan screen pesan
                Intent i = new Intent(getApplicationContext(), atur_murky.class);
                startActivity(i);
            }
        });

    }
}
