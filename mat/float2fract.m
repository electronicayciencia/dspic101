function [ output ] = float2fract( y )
%FLOAT2FRACT Transform a floating point number between 0 and 1 to dspic 16bit integer in signed fractionary format.

    y(y>=1) = 1-2^-15;
    y(y<=-1) = -1;
    output = int16(round(y*2^15));

end

