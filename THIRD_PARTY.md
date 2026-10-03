# Tools used

The Rust traversal controller and sandbox code were created for this project. The mesh, texture, and animation data came from the locally installed game and have not been assigned a new license.

- Bevy 0.19.1: https://github.com/bevyengine/bevy (MIT or Apache-2.0).
- ALERT, by Tkachov: https://github.com/Tkachov/ALERT (GPL-3.0). Used for Remastered DAT1 model decoding. License: tools/ALERT-main/LICENSE.txt.
- Overstrike, by Tkachov: https://github.com/Tkachov/Overstrike (GPL-3.0). Archive and serialized configuration schemas used as reference. Its license is retained in tools/Overstrike-main/.
- Luna Engine IO Tools, by Pcniado: https://github.com/Pcniado/luna_engine_io_tools (GPL-3.0). Its Blender animation importer is used by convert_character.py with a Remastered section compatibility adapter. Its license is retained in tools/luna_engine_io_tools-main/.
- IGHASHES, by Pcniado: https://github.com/Pcniado/IGHASHES. The asset-name hash list was used to locate installed assets.
- Blender 5.0.1: https://www.blender.org (GPL). Portable conversion runtime, with bundled license information in tools/blender-5.0.1-windows-x64/.
- Ghidra 12.1.4: https://github.com/NationalSecurityAgency/ghidra (Apache-2.0, with separately licensed components). Used to produce local pseudocode research; bundled notices are retained.
- Eclipse Temurin 21: https://adoptium.net. Portable Java runtime for Ghidra; bundled notices are retained.

The conversion scripts import the GPL tools for asset decoding. Those dependencies are not linked into the Rust executable.
