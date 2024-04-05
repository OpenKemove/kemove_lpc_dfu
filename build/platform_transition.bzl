"""Rules for applying a platform transition"""

def _platform_transition_impl(_settings, attr):
    return {
        "//command_line_option:platforms": str(attr.platform),
    }

_platform_transition = transition(
    implementation = _platform_transition_impl,
    inputs = [],
    outputs = [
        "//command_line_option:platforms",
    ],
)

def _with_platform_impl(ctx):
    src_default_info = ctx.attr.src[DefaultInfo]
    return [DefaultInfo(files=src_default_info.files)]

with_platform = rule(
    implementation = _with_platform_impl,
    cfg = _platform_transition,
    attrs = {
        "src": attr.label(mandatory = True, providers=[DefaultInfo]),
        "platform": attr.label(mandatory = True),
    },
    provides = [DefaultInfo]
)
