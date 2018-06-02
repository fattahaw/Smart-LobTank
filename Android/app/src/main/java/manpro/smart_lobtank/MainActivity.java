package manpro.smart_lobtank;

import android.content.DialogInterface;
import android.content.Intent;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        Button cek_suhu = findViewById(R.id.btn_suhu);
        Button cek_kekeruhan = findViewById(R.id.btn_murky);
        Button cek_ph = findViewById(R.id.btn_ph);


        cek_suhu.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // Menampilkan screen pesan
                Intent i = new Intent(getApplicationContext(), suhu.class);
                startActivity(i);
            }
        });

        cek_kekeruhan.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // Menampilkan screen pesan
                Intent i = new Intent(getApplicationContext(), kekeruhan_air.class);
                startActivity(i);
            }
        });

        cek_ph.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // Menampilkan screen pesan
                Intent i = new Intent(getApplicationContext(), cek_ph.class);
                startActivity(i);
            }
        });

    }

        @Override
        public boolean onCreateOptionsMenu(Menu menu) {
            getMenuInflater().inflate(R.menu.dashboard, menu);
            return true;
        }

        @Override
        public boolean onOptionsItemSelected(MenuItem item) {
            switch (item.getItemId()) {
                case R.id.bantuan:
                    Intent intent = new Intent(getApplicationContext(), bantuan.class);
                    intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                    startActivity(intent);
                    return true;
                case R.id.ubahsuhu:
                    Intent intent2 = new Intent(getApplicationContext(), atur_suhu.class);
                    intent2.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                    startActivity(intent2);
                    return true;
                case R.id.ubahph:
                    Intent intent3 = new Intent(getApplicationContext(), atur_ph.class);
                    intent3.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                    startActivity(intent3);
                    return true;
                case R.id.ubahmurky:
                    Intent intent4 = new Intent(getApplicationContext(), atur_murky.class);
                    intent4.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                    startActivity(intent4);
                    return true;
                case R.id.about:
                    Intent intent5 = new Intent(getApplicationContext(), about.class);
                    intent5.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                    startActivity(intent5);
                    return true;
                default:
                    return super.onOptionsItemSelected(item);
            }
        }

    @Override
    public void onBackPressed() {

        AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);
        builder.setTitle(R.string.app_name);
        builder.setIcon(R.mipmap.ic_launcher);
        builder.setMessage("Do you want to exit?")
                .setCancelable(false)
                .setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        finish();
                    }
                })
                .setNegativeButton("No", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        dialog.cancel();
                    }
                });
        AlertDialog alert = builder.create();
        alert.show();
    }
}
