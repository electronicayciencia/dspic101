function [ output ] = fract2float( y )
%FRACT2FLOAT Transform a signed 16bit integer in signed fractionary format to floating point number between 0 and 1.

    y(y>2^15-1) = 2^15-1;
    y(y<-2^15) = -2^15;
    
    y = double(y);
    
    y(y > 2^15-1) = -y(y > 2^15-1);
    %y = y - 2^15
    output = y / 2^15;

end

