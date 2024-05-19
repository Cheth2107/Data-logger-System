// int sensor1 = A0;
// int sensor2 = A1;

// String dataLabel1 = "Potentiometer";
// String dataLabel2 = "Photoresistor";
// bool label = true;

// int data1, data2, curr1, curr2;

// float percent = 0.05;
// int threshold = 1024*percent;

// int freq = 1000;

// void setup(){
//   Serial.begin(9600);
//   pinMode(sensor1, INPUT);
//   pinMode(sensor2, INPUT);
//   //Serial.print("Current Threshold is +/- ");
//   //Serial.print(int(percent*100));
//   //Serial.print("%");
// }

// void loop(){

//   while(label){
//     Serial.print(dataLabel1);
//     Serial.print(",");
//     Serial.print(dataLabel2);
//     label = false;
//   }

//   data1 = analogRead(sensor1);
//   data2 = analogRead(sensor2);

//   if((curr1 >= data1+threshold || curr1 <= data1-threshold) || (curr2 >= data2+threshold || curr2 <= data2-threshold)){
//     Serial.print(data1);
//     Serial.print(",");
//     Serial.print("data2");

//     curr1 = data1;
//     curr2 = data2;
//   } 
// }




int sensor1 = A0;
int sensor2 = A1;

void setup(){
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
}




//globals
float percent = 0.05;
int threshold = 1024*percent; //within x% in either direction
int freq = 1000; //data collection frequency ~x milliseconds
int curr1, curr2;

void loop(){
    int data1 = analogRead(sensor1);
    int data2 = analogRead(sensor2);

    if((curr1 >=data1+threshold || curr1 <=data1-threshold) || (curr2>=data2+threshold || curr2<=data2-threshold) ){

        //Display Data to Serial Monitor
	Serial.print(data1);
	Serial.print(",");
	Serial.println(data2);

	//set the current equal to the data
	curr1 = data1;
	curr2 = data2;
    }
    delay(freq);
}