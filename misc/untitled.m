data = importdata('input.txt');
data = data(9:2248);
i = 1;
j = 1;

%regexprep(data, '\', '')
for i = 1:length(data)
    array = 

for i = 1:2240
    while data{j} ~= '\'
        array(i) = array(i) + data(j);
        j = j+1;
    end
    i = 1+1;
    
end


