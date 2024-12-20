#---------------------
if vEnable
    then
    {
        if vEnable == 1 then
            {
                vStatus = "Включено";
                vEWaitTime = "00 мин";
            }
        else
        {
            vStatus = "Отключено";
            vEWaitTime = "ХХ мин";
        };
    };
#---------------------
if timerCheck
    then
    {
        vLoad = getUptime();
        vRSSI = getRSSI();
        if vEnable == 1 then
            {
                vStatus = "Включено";
                vEWaitTime = "00 мин";
            }
        else
        {
            vStatus = "Отключено";
            vEWaitTime = "ХХ мин";
        };
    };