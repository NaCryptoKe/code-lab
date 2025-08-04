import numpy as np
import matplotlib.pyplot as plt

# Generate data
np.random.seed(42)  # for reproducibility
X = np.random.uniform(1, 10, 50)
noise = np.random.normal(0, 2, X.shape)
y = 5 * X + noise

# Prediction function
def predict(X, m, b):
    return m * X + b

# Cost function (Mean Squared Error)
def cost_function(y_true, y_pred):
    return np.mean((y_true - y_pred) ** 2)

# Gradient Descent parameters
m, b = 0.0, 0.0          # initial guess
learning_rate = 0.01
epochs = 1000

n = len(X)

for i in range(epochs):
    y_pred = predict(X, m, b)
    error = y_pred - y
    
    # Compute gradients
    dm = (2/n) * np.dot(error, X)
    db = (2/n) * np.sum(error)
    
    # Update parameters
    m -= learning_rate * dm
    b -= learning_rate * db

    if i % 100 == 0:
        print(f"Epoch {i}: Cost = {cost_function(y, y_pred):.4f}, m = {m:.4f}, b = {b:.4f}")

# Final predictions and plot
plt.scatter(X, y, color='blue', alpha=0.7, label='Data')
plt.plot(X, predict(X, m, b), color='red', label=f'Fit: y={m:.2f}x + {b:.2f}')
plt.xlabel("Hours Studied")
plt.ylabel("Exam Score")
plt.legend()
plt.savefig("gradient_descent_fit.png")
print("Training complete. Plot saved as 'gradient_descent_fit.png'")

