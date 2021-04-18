use serde::Serialize;
use serde_json;

pub fn save_configuration(config: &HashMap<String, String>) -> std::io::Result<()> {
    let writer = File::create(config_filename())?;
    let mut serializer = serde_json::Serialize::new(writer);

    config.serialize(&mut serializer)?;

    Ok(())
}