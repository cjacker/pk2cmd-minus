DESTDIR=
PREFIX=/usr

all: build

build:
	make -C pk2cmd/pk2cmd linux

install: build
	mkdir	-p $(DESTDIR)/$(PREFIX)/bin
	mkdir	-p $(DESTDIR)/$(PREFIX)/share/pk2
	mkdir -p $(DESTDIR)/etc/udev/rules.d
	install -m0755 pk2cmd/pk2cmd/pk2cmd $(DESTDIR)/$(PREFIX)/bin/
	install -m0644 pk2cmd/pk2cmd/PK2DeviceFile.dat $(DESTDIR)/$(PREFIX)/share/pk2
	install -m0644 pk2cmd/release/PK2V023200.hex $(DESTDIR)/$(PREFIX)/share/pk2
	install -m0644 pk2cmd/release/PK3OSV020005.hex $(DESTDIR)/$(PREFIX)/share/pk2
	install -m0644 pk2cmd/release/PK3BLV011405.hex $(DESTDIR)/$(PREFIX)/share/pk2
	install -m0644 pk2cmdminus_supported_devices.txt $(DESTDIR)/$(PREFIX)/share/pk2
	install -m0644 PICkit2-Device-File-Editor.exe $(DESTDIR)/$(PREFIX)/share/pk2/
	install -m0755 pk2-device-file-editor $(DESTDIR)/$(PREFIX)/bin/
	install -m0644 60-pickit.rules $(DESTDIR)/etc/udev/rules.d/ 
