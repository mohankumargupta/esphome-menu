import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID, CONF_KEY, CONF_NAME, CONF_OPTIONS
from esphome import automation

# from esphome import pins

tft_menu_ns = cg.esphome_ns.namespace("tft_menu")
TFTMenuComponent = tft_menu_ns.class_("TFTMenuComponent", cg.Component)
KeyPressedAction = tft_menu_ns.class_("KeyPressAction", automation.Action)

CONF_MENU = "menu"

# empty_component_ns = cg.esphome_ns.namespace('oled')
# OledComponent = empty_component_ns.class_("Oled", cg.Component)

# CONF_OLED = "OledComponent"

# MULTI_CONF = True

# INDEXES = set()

# def validate_index(value):
# value = cv.int_(value)
# if value < 1 or value > 9:
#     raise cv.Invalid("Index must be between 1 and 9")
# if value in INDEXES:
#     raise cv.Invalid("Index must be unique")
# INDEXES.add(value)
# return value

MENU_ITEM_SCHEMA = cv.Schema(
    {
        cv.Required(CONF_NAME): cv.string_strict,
        cv.Optional(CONF_OPTIONS): cv.ensure_list(cv.string_strict)
    }
)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(TFTMenuComponent),
        cv.Required(CONF_MENU): cv.ensure_list()
    }
)

def check_key(obj):
    key = obj[CONF_KEY]
    def key_error():
        raise cv.Invalid("Invalid key for keypad matrix. Valid keys are: 0-9,*,#")
    valid_keys = [str(i) for i in range(10)]
    valid_keys += ["A", "B", "C", "D", "*", "#"]
    if key not in valid_keys:
        key_error()
    if key.isdigit():
        obj[CONF_KEY] = int(key)
    else:
        obj[CONF_KEY] = {'A': 0x0A, 'B': 0x0B, 'C': 0x0D, '*': 0x0E, '#': 0x0F}[key]
    return obj


#automation.maybe_simple_id({cv.GenerateID(): cv.use_id(TFTMenuComponent)})

@automation.register_action(
    "tft_menu.keypress",
    KeyPressedAction,
    cv.All(
      cv.Schema({
        cv.GenerateID(): cv.use_id(TFTMenuComponent),
        cv.Required(CONF_KEY): cv.string
    }),
    check_key
    )

)

async def tft_menu_keypress_to_code(config, action_id, template_arg, args):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    cg.add(var.set_key(config[CONF_KEY]))
    return var


# CONFIG_SCHEMA = cv.Schema({
#     cv.GenerateID(): cv.declare_id(OledComponent),
#     cv.Required(CONF_SDA): pins.internal_gpio_output_pin_number,
#     cv.Required(CONF_SCL): pins.internal_gpio_output_pin_number,
#     cv.Required(CONF_INDEX, msg="missing field index"): validate_index,
#     cv.Optional(CONF_ADDRESS, default=0x3C): cv.i2c_address,

# }).extend(cv.COMPONENT_SCHEMA)


def to_code(config):
    menu = list(config[CONF_MENU])
    main_menu = [item['name'] for item in menu]
    menu_options = [item['options'] for item in menu]

    array = cg.ArrayInitializer(*main_menu,multiline=True)
    #vec_string = str(cg.std_vector.template(cg.TemplateArguments(cg.std_string)))
    #expr = cg.RawExpression(f"{vec_string} menu = {array}")
    #statement = str(cg.statement(expr))

    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    cg.add(var.set_top_menu(array))



   
    
    #top_menu_cg = cg.new_variable("menu", "null", ct.std_vector.template(cg.std_string))
    #cg.add(cg.(ct.std_vector.template(cg.std_string), "", "top_menu", r"{}"))

    # cg.add_build_flag("-DU8X8_NO_HW_SPI")
    # cg.add_build_flag("-DU8X8_NO_HW_I2C")
    # #cg.add_build_flag("-DU8X8_USE_PINS")
    # cg.add_library("olikraus/U8g2", None)

    # var = cg.new_Pvariable(config[CONF_ID])
    # yield cg.register_component(var, config)
    # cg.add(var.set_pins(config[CONF_SDA], config[CONF_SCL]))
    # cg.add(var.set_index(config[CONF_INDEX]))
