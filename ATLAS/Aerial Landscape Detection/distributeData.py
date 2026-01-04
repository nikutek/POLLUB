import os
import shutil
import random

# ==========================
# KONFIGURACJA
# ==========================
DATA_DIR = "data"
TRAIN_DIR = "train"
VAL_DIR = "val"

TRAIN_RATIO = 0.8  # 80% train, 20% val
SEED = 42          # dla powtarzalności

IMAGE_EXTENSIONS = (".jpg", ".jpeg", ".png", ".bmp", ".tif", ".tiff")

# ==========================
# FUNKCJE POMOCNICZE
# ==========================

def clear_directory(path):
    """Usuwa wszystkie pliki i foldery w danym katalogu."""
    if not os.path.exists(path):
        return
    for item in os.listdir(path):
        item_path = os.path.join(path, item)
        if os.path.isdir(item_path):
            shutil.rmtree(item_path)
        else:
            os.remove(item_path)

def get_images(folder):
    """Zwraca listę ścieżek do obrazów w folderze."""
    return [
        os.path.join(folder, f)
        for f in os.listdir(folder)
        if f.lower().endswith(IMAGE_EXTENSIONS)
    ]

# ==========================
# GŁÓWNA LOGIKA
# ==========================

def split_dataset():
    random.seed(SEED)

    # Wyczyść train i val
    clear_directory(TRAIN_DIR)
    clear_directory(VAL_DIR)

    os.makedirs(TRAIN_DIR, exist_ok=True)
    os.makedirs(VAL_DIR, exist_ok=True)

    # Każdy folder w data = osobna klasa
    classes = [
        d for d in os.listdir(DATA_DIR)
        if os.path.isdir(os.path.join(DATA_DIR, d))
    ]

    if not classes:
        raise ValueError("Brak folderów klas w katalogu 'data'.")

    for cls in classes:
        class_path = os.path.join(DATA_DIR, cls)
        images = get_images(class_path)

        if len(images) == 0:
            print(f"[WARN] Brak obrazów w klasie: {cls}")
            continue

        random.shuffle(images)

        split_idx = int(len(images) * TRAIN_RATIO)
        train_images = images[:split_idx]
        val_images = images[split_idx:]

        train_class_dir = os.path.join(TRAIN_DIR, cls)
        val_class_dir = os.path.join(VAL_DIR, cls)

        os.makedirs(train_class_dir, exist_ok=True)
        os.makedirs(val_class_dir, exist_ok=True)

        for img in train_images:
            shutil.copy2(img, train_class_dir)

        for img in val_images:
            shutil.copy2(img, val_class_dir)

        print(
            f"[OK] {cls}: "
            f"{len(train_images)} train / {len(val_images)} val"
        )

    print("\n✅ Podział datasetu zakończony.")

# ==========================
# ENTRY POINT
# ==========================

if __name__ == "__main__":
    split_dataset()
