#include <driver/dac.h>

void setup() {
  dac_output_enable(DAC_CHANNEL_1);
  dac_output_enable(DAC_CHANNEL_2);

}

void loop() {
  int col, line;
  for(line = 0; line < 100; line++) {
    dac_output_voltage(DAC_CHANNEL_1, line * 2);
    for(col = 0; col < 100; col++) {
      if(col % 3 == 0) {
        dac_output_voltage(DAC_CHANNEL_1, line * 2);
        dac_output_voltage(DAC_CHANNEL_2, col * 2);
      }
      else
      {
        dac_output_voltage(DAC_CHANNEL_1, 0);
        dac_output_voltage(DAC_CHANNEL_2, col * 2);
      }
   
    }
  }
  dac_output_voltage(DAC_CHANNEL_1, 254);
  dac_output_voltage(DAC_CHANNEL_2, 254);
  delay(20);
}
