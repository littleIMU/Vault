---
priority: 3rd
status: dormant
url: 
category: 
parent: 
children: 
link_action: 
link_topic: 
link_project: 
link_course: 
link_notes: 
---

Property: turn image to text

[Installing additional language packs - ocrmypdf 13.7.1.dev11+gb458b142 documentation](https://ocrmypdf.readthedocs.io/en/latest/languages.html)

# install

install tesseract-ocr

```
sudo add-apt-repository ppa:alex-p/tesseract-ocr-devel
sudo apt update
sudo apt install tesseract-ocr 
sudo apt install tesseract-ocr-<language>
```

install gimagereader

```
sudo add-apt-repository ppa:sandromani/gimagereader
sudo apt update
sudo apt install gimagereader
```

# problem

**"No tesseract languages are available for use"**

→ move "usr/share/tesseract-ocr/5/tessdata/eng.traineddata” to 4.00