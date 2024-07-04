import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID, CONF_SDA, CONF_SCL, CONF_ADDRESS, CONF_INDEX
from esphome import pins

empty_component_ns = cg.esphome_ns.namespace('oled')
OledComponent = empty_component_ns.class_("Oled", cg.Component)

CONF_OLED = "OledComponent"

MULTI_CONF = True

INDEXES = set()

def validate_index(value):
    value = cv.int_(value)
    if value < 1 or value > 9:
        raise cv.Invalid("Index must be between 1 and 9")
    if value in INDEXES:
        raise cv.Invalid("Index must be unique")
    INDEXES.add(value)
    return value    

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(OledComponent),
    cv.Required(CONF_SDA): pins.internal_gpio_output_pin_number,
    cv.Required(CONF_SCL): pins.internal_gpio_output_pin_number,
    cv.Required(CONF_INDEX, msg="missing field index"): validate_index,
    cv.Optional(CONF_ADDRESS, default=0x3C): cv.i2c_address, 

}).extend(cv.COMPONENT_SCHEMA)



def to_code(config):
    cg.add_build_flag("-DU8X8_NO_HW_SPI")
    cg.add_build_flag("-DU8X8_NO_HW_I2C")
    #cg.add_build_flag("-DU8X8_USE_PINS")
    cg.add_library("olikraus/U8g2", None)
    
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    cg.add(var.set_pins(config[CONF_SDA], config[CONF_SCL]))
    cg.add(var.set_index(config[CONF_INDEX]))


    
