% Sampling Rate
clear
SR = 5000;

% Band limits
BASS_LIMIT = 200;
TREB_LIMIT = 1000;
FILTER_ORDER = 75-1;

% Create low, med and high filters
filter_bass = fir1(FILTER_ORDER, 2*BASS_LIMIT/SR);
filter_meds = fir1(FILTER_ORDER, 2*[BASS_LIMIT/SR, TREB_LIMIT/SR]);
filter_treb = fir1(FILTER_ORDER, 2*TREB_LIMIT/SR, 'high');

% Take into account resollution losses in DSP
filter_bass = fract2float(float2fract(filter_bass));
filter_meds = fract2float(float2fract(filter_meds));
filter_treb = fract2float(float2fract(filter_treb));

% Get the frequency response
plotpoints = 512;
f_bass = freqz(filter_bass,1,plotpoints,SR);
f_meds = freqz(filter_meds,1,plotpoints,SR);
f_treb = freqz(filter_treb,1,plotpoints,SR);

x = [0:plotpoints-1]/plotpoints * SR/2;

plot(x, abs(f_bass));
hold on
plot(x, abs(f_meds));
plot(x, abs(f_treb));
hold off
grid on

float2fract(filter_bass')
