import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split
from sklearn.datasets import fetch_lfw_people
from sklearn.decomposition import PCA
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
from sklearn.neural_network import MLPClassifier
import numpy as np
import os,cv2

def plot_gallery(images, titles, h, w, n_rows=3, n_cols=4):
    """Helper function to plot a gallery of portraits"""
    plt.figure(figsize=(1.8 * n_cols, 2.4 * n_rows))
    plt.subplots_adjust(bottom=0, left=.01, right=.99, top=.90, hspace=.35)
    for i in range(n_rows * n_cols):
        plt.subplot(n_rows, n_cols, i + 1)
        plt.imshow(images[i].reshape((h, w)), cmap=plt.cm.gray)
        plt.title(titles[i], size=12)
        plt.xticks(())
        plt.yticks(())
        dir_name = "C:\\Users\\manip\\OneDrive\\Desktop\\AI\\dataset\\dataset\\faces\\"
y = []
x = []
target_names = []
person_id = 0
h = w = 300
n_samples = 0
class_names = []

for person_name in os.listdir(dir_name):
    dir_path = os.path.join(dir_name, person_name)  # Construct the directory path
    class_names.append(person_name)
    for image_name in os.listdir(dir_path):
        image_path = os.path.join(dir_path, image_name)  # Construct the image path
        img = cv2.imread(image_path)  # Read the input image
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)  # Convert into grayscale
        resized_image = cv2.resize(gray, (h, w))  # Resize image to 300x300 dimensions
        v = resized_image.flatten()  # Convert matrix to vector
        x.append(v)
        n_samples = n_samples + 1  # Increase number of samples
        y.append(person_id)  # Adding the categorical label
    target_names.append(person_name)  # Adding person name
    person_id = person_id + 1

# Transform lists to numpy arrays
y = np.array(y)
x = np.array(x)
target_names = np.array(target_names)

n_features = x.shape[1]
print(y.shape, x.shape, target_names.shape)
print("Number of samples:", n_samples)

n_classes = len(class_names)

print("Total dataset size:")
print("n_samples: %d" % n_samples)
print("n_features: %d" % n_features)
print("n_classes: %d" % n_classes)
x_train,x_test,y_train,y_test= train_test_split(x,y,test_size=0.25,random_state=42)
n_components = 150
print("Extracting the tod %d eigenfaces from %d faces"%(n_components,x_train.shape[0]))
pca = PCA(n_components=n_components,svd_solver='randomized',whiten=True).fit(x_train)
eigenfaces = pca.components_.reshape((n_components,h,w))
eigenface_titles = ["eigenface %d" % i for i in range(eigenfaces.shape[0])]
plot_gallery(eigenfaces,eigenface_titles,h,w)
plt.show()

x_train_pca = pca.transform(x_train)
x_test_pca = pca.transform(x_test)
print(x_train_pca.shape,x_test_pca.shape)

lda = LinearDiscriminantAnalysis()
lda.fit(x_train_pca,y_train)
x_train_lda = lda.transform(x_train_pca)
x_test_lda = lda.transform(x_test_pca)
print("Projecct done.....")
clf = MLPClassifier(random_state=1, hidden_layer_sizes=(10,10),max_iter=1000,verbose=True).fit(x_train_lda,y_train)
print("Model weights:")
model_info = [coef.shape for coef in clf.coefs_]
print(model_info)
y_pred=[]; y_prob=[]
for test_face in x_test_lda:
    prob = clf.predict_proba([test_face])[0]
    class_id = np.where(prob==np.max(prob))[0][0]
    y_pred.append(class_id)
    y_prob.append(np.max(prob))

y_pred = np.array(y_pred)

prediction_titles=[]
true_positive = 0
for i in range(y_pred.shape[0]):
    true_name = class_names[y_test[i]]
    pred_name = class_names[y_pred[i]]
    result = 'pred: %s,pr: %s \ntrue: %s'%(pred_name, str(y_prob[i])[0:3],true_name)
    prediction_titles.append(result)
    if true_name == pred_name:
        true_positive= true_positive+1

print("Accuracy:",true_positive*100/y_pred.shape[0])
plot_gallery(x_test,prediction_titles,h,w)
plt.show()

        



