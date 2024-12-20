 #----опрос по таймеру
if timerCheck then
    {
       #vTest = timerCheck ;
         # проверка Перезагрузка
        if vReset  then
            {
                reboot();
            };
       # проверка включения
        if vEnable == 1 then
            {
                vEWaitTime := timerCheck / 30 + " мин";
                 #сенсор воды инвертированный
                if digitalRead(4) ==  1 then
                    {
                        digitalWrite(5,0);
                        if vEnablePump == 1 then {
                         timerCheck.reset();
                        };
                        vEnablePump := 0;
                        vPump := "❌";
                        vSensTxt := "♨️";
                    }
                   else { 
                         vSensTxt := "💧";
                     if vEnablePump == 0 then
                     {
                      #моргание
                       digitalInvert(2);
                     };
                    };
                 #проверка таймера ожидания
                if timerCheck == 1  then
                    {
                         #сенсор воды инвертированный
                        if digitalRead(4) == 0 then
                            {
                             vTest = "digitalRead(4) == 0";   
                             digitalWrite(5,1);
                               vEnablePump := 1;
                                vPump := "🚿";
                                #out_Pin_2 инвертированный
                                digitalWrite(2,0);
                            }
                        else
                        {   
                            #timerCheck.stop();
                           vTest = "digitalRead(4) == 1";
                        };
                    };
            }
        else
        {
              vSensTxt := "❌";
              vEWaitTime := "❌";
             digitalWrite(5,0);
              vEnablePump := 0;
              vPump := "❌";
             #out_Pin_2 инвертированный
             digitalWrite(2,1);
         };
};