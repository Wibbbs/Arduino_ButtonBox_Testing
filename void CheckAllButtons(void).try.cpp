void CheckAllButtons(void)
{
  if (buttbx.getKeys())
  {
    for (int i = 0; i < LIST_MAX; i++)
    {
      if (buttbx.key[i].stateChanged)
      {
        Serial.println(buttbx.key[i].kcode);
        if (buttbx.key[i].kcode == 0)
        {
          switch (buttbx.key[i].kstate)
          {
          case PRESSED:
          case HOLD:
            Joystick.setButton(buttbx.key[i].kchar, 1);
            delay(100);
            Joystick.setButton(buttbx.key[i].kchar, 0);
            Serial.println("0 Button RELEASED");
            break;
          case RELEASED:
            Joystick.setButton(buttbx.key[i].kchar, 1);
            delay(100);
            Joystick.setButton(buttbx.key[i].kchar, 0);
            Serial.println("0 Button RELEASED");
            break;
          case IDLE:
            break;
          }
        }
        else
        {
          switch (buttbx.key[i].kstate)
          {
          case PRESSED:
          case HOLD:
            Joystick.setButton(buttbx.key[i].kchar, 1);
            break;
          case RELEASED:
          case IDLE:
            Joystick.setButton(buttbx.key[i].kchar, 0);
            break;
          }
        }
      }
    }
  }
}