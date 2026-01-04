from ultralytics import YOLO
import os
# Load a model
model = YOLO("yolo11n-cls.pt")  # load a pretrained model (recommended for training)

# Train the model
PATH = os.getcwd()
results = model.train(data=PATH,
                      epochs=5,
                      imgsz=256,
                      project="runs",
                      name="classify")