int band_pass_fir(struct morse *_m, int16_t *_signal, int _len)
{
  // _m->signal (int16 array) is my desired output
  // _signal (int16 array) contains the actual amplitude modulated data received from the signal
  // _len is the length of _signal

  int i = 2;

  const float b0 = 0.1205498139,
              b1 = 0,
              b2 = -0.1205498139,
              a1 = -1.7626236142,
              a2 = 0.8273910712;

  while (i < _len)
  {
    _m->signal[i] = (int16_t)(b0 * _signal[i]) +
                    (int16_t)(b1 * _signal[i-1]) +
                    (int16_t)(b2 * _signal[i-2]) -
                    (int16_t)(a1 * _m->signal[i-1]) -
                    (int16_t)(a2 * _m->signal[i-2]);

    _m->signal[i-2] = _m->signal[i-1];
    _m->signal[i-1] = _m->signal[i];

    i++;
  }
}