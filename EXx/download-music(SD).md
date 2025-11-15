<!-- 只在原始碼裡看的說明：以下是把 YouTube 轉 MP3 存進 SD 卡的指令 -->

```bash
yt-dlp \
  -x \                          # 只提取音訊
  --audio-format mp3 \          # 轉成 MP3
  --audio-quality 0 \           # 最高品質
  --embed-thumbnail \           # 嵌入封面
  --add-metadata \              # 加上中繼資料
  --restrict-filenames \        # 安全檔名
  -o "/Volumes/MUSICSD/%(title)s.%(ext)s" \
  "PASTE_YOUTUBE_URL_HERE"      # 貼上連結

// 好下指令格式，不換行(轉成m4a)
yt-dlp -x --audio-format m4a --audio-quality 0 \
  --embed-thumbnail --add-metadata --restrict-filenames \
  -o "/Volumes/MUSICSD/%(title)s.%(ext)s" \
  "
