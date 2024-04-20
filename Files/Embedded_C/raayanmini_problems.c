*************************************************************** <<<<<<< PROBLEM_ON_RAAYANMINI_STM32F401RBT6_BOARD >>>>>>> *******************************************************************************


(1)  LED keep ON & OFF with low contrast.

sol: It occurs when microseconds function executed first before the milliseconds and that microseconds delay is low,it occurs even if the delay is high.We have to execute milliseconds funnctuon first and then microseconds.

(2) Only one LED is blinking among 2.

sol: The another LED must connected to switch and that switch can be initialized to zero.

(3) LED keep on glowing witout delay even when we apply the delay.

sol: The LED delay must be high like (6Lacs,12 Lacs....).

(4)Problem at Counting the no.of times the switch is pressed,is very high and is not proper.

sol: * The delay must be greater i.e.12 Lacs.
     * The LED OFF function must be in the loop.

(5) LED is not blinking.

sol: The physical addresses maybe wrong (or) the ON & OFF condiktions wrong.

(6) LED keep ON with interrupt.

sol: The STK_VAL must be assigned with some garbage value for the first time then only the STK_LOAD value at 21st bit be activated.

(7) LED keep ON even after applyinng the delay.

sol: LED must be initialized to zero  then only the LED stops.

(8) What if we are not assigning IDR value to zero.

sol: It is not ready to take the input.

(9) Why sometimes all the addresses and assigning values are true but LED doesn't work.

sol: There maybe some Problems in assigning the ports to particular input and output.

(10) Raayanminin STM32F401RBT6 board is negstive logic but buzzer is not processing.

sol: Because the buzzer is a positive logic in Raayanminin STM32F401RBT6.

(11) Why the delay can't be processing in a accurate manner.

sol: To maintain the accurate delay,it is  better to use system timer clock process.

(12) ST Link problem.

sol: Goto Target menu and select debug option and choose ST Link debugger and goto settings which is besides ST Link and select flash download and select runtime.

(13) LED is not activated when switch is pressed.

sol: First we have to check that the switch is PULL UP (or) PULL DOWN.

(14) why we are getting the output in ADC after all conversion why not for each conversion.

sol: Enable EOC then we can get output at each conversion.

(15) why  the data is overriding in ADC conversion.

sol: Every time we have to read the data then the data can't be override.

(16) Why the data is not transmitting and receiving in USART.

sol: Make enable the clock to UART in APB2_ENR register.(or) The address or logics maybe wrong.

(17) After all that we have only one reason for not transmitting/receiving the data in tera term.

sol: Make sure that the Wi-Fi transmitter is connected to USART receiver and Wi-Fi receiver to USART transmitter.

(18) Target not found error while loading the code.

sol: We have to download the STM32 demonstrator then connect the board with TTL(Transistor-Transistor logic) as tx-tx and rx-rx.Set the boot then reset.Select the boot option then solve it.

