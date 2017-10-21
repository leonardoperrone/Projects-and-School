X = load('spam-training.txt');
Y = load('train-labels.txt');
test_set = load('spam-testing.txt');
true_test_labels = load('test-labels.txt');

Nb=fitcnb(X,Y, 'Distribution', 'mn');

predicted_labels = predict(Nb,test_set);

difference_label = predicted_labels - true_test_labels;

ones = find(difference_label, 1);
zeros = length(difference_label) - ones;

accuracy = (ones/(length(difference_label)))*100;

