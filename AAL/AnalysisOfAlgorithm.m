function [ analysisVector ] = AnalysisOfAlgorithm(  )

%This func is to analyze whether the prediction of algorithm is precise. If
%the ouput of the analysisVector, and its elements are quite close to 1, 
%then the prediction is correct

disp('Make your prediction about algorithm running time. Type x -> O(n^x): ');
prompt = '...';
x = input(prompt);
fileID = fopen('rawRunningTimeData.txt','r');
A=fscanf(fileID,'%f');

sizeVar=floor(size(A)/2);


for i=2:size(A)
    if mod(i,2)==0
        inputSize(i/2) = A(i);
    else 
        inputTime(floor((i+1)/2)) = A(i);
    end
end
inputTime(1) = A(1);
medianTime = median(inputTime);
medianSize = median(inputSize);

coefficient = medianSize^x / medianTime;


for i=1:sizeVar
    analysisVector(i) = inputTime(i) * coefficient / inputSize(i).^x;
end

figure ;
plot(analysisVector);
title('Analysis');
figure ;
plot(inputSize,inputTime);
title('Running Time as a func of input size');
xlabel('input size');
ylabel('Running time [ms]');
end

