load("//build:platform_transition.bzl", "with_platform")

cc_binary(
    name = "dfu_elf",
    srcs = [
        "main.c",
        "vectors.S",
    ],
    deps = [
        "linker.ld",
    ],
    copts = [
        "-ffreestanding",
        "-nostartfiles",
    ],
    linkopts = [
        "-ffreestanding",
        "-nostartfiles",
        "-Tlinker.ld"
    ],
    target_compatible_with = [
        "@platforms//cpu:armv6-m",
        "@platforms//os:none",
    ],
)

with_platform(
    name="lpc11u35dev",
    src=":dfu_elf",
    platform="//platforms/lpc_11u35_dev"
)
