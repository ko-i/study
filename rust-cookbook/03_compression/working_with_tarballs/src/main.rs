
use std::fs::File;

use flate2::Compression;
use flate2::read::GzDecoder;
use flate2::read::GzEncoder;
use tar::Archive;

fn decompress(path: &str) -> Result<(), std::io::Error> {
    let tar_gz = File::open(path)?;
    let tar = GzDecoder::new(tar_gz);
    let mut archive = Archive::new(tar);
    archive.unpack(".")?;

    Ok(())
}

fn compress() -> Result<(), std::io::Error> {
    let tar_gz = File::create("my_archive.tar.gz")?;
    let enc = GzEncoder::new(tar_gz, Compression::default());
    let mut tar = tar::Builder::new(enc);
    tar.append_dir_all(".", "/log")?;

    Ok(())
}

fn main() -> Result<(), std::io::Error> {
    // compress()?;
    let path = "my_archive.tar.gz";
    decompress(path)?;

    Ok(())
}
