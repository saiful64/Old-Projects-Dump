package com.example.cricketapplication;

import android.os.Bundle;

import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.snackbar.Snackbar;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.text.DecimalFormat;

public class MainActivity extends AppCompatActivity {

    EditText etChirps;
    Button btCalculate;
    TextView tvResults;
    DecimalFormat formatter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        etChirps= findViewById(R.id.etChirps);
        btCalculate= findViewById(R.id.btCalculate);
        tvResults= findViewById(R.id.tvResults);

        tvResults.setVisibility(View.GONE);

        formatter = new DecimalFormat("#0.00");

        btCalculate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                if (etChirps.getText().toString().isEmpty())
                {
                    Toast.makeText(MainActivity.this, "Please enter number of chirps", Toast.LENGTH_SHORT).show();
                }
                else{
                    int chirps=Integer.parseInt(etChirps.getText().toString().trim());

                    double temp = (chirps /3.0) + 4 ;

                    String results = "The approximate temperature outside is " + formatter.format(temp) + " degree celsius";

                    tvResults.setText(results);
                    tvResults.setVisibility(View.VISIBLE);
                }
            }
        });

    }
}

