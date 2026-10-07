from PIL import Image

jpg_file = "./Resources/Bliss.jpg"

im = Image.open(jpg_file)    # 開啟圖片檔案
name = jpg_file.lower().split('/')[::-1][0]         # 將檔名換成小寫 ( 避免 JPG 與 jpg 干擾 )
png = name.replace('jpg','png')  # 取出圖片檔名，將 jpg 換成 png
im.save(f'./Resources/{png}', 'png')   # 轉換成 png 並存檔
