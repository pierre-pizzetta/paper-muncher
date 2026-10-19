#include <karm/test>

import Vaev.Engine;

using namespace Karm;
using namespace Karm::Literals;

namespace Vaev::Style::Tests {

test$("vaev-style-serialize-props") {
    auto registry = defaultRegistry();

    auto testCase = [&](Str name, Str input, Str expected) -> Res<> {
        auto prop = try$(registry.parseValue(Symbol::from(name), input, {}));
        Io::StringWriter w;
        try$(prop->serialize(w));
        assertEq$(w.take(), expected);
        return Ok();
    };

    // Sizing, Display & Colors
    try$(testCase("width", "auto", "auto"));
    try$(testCase("width", "0", "0px"));
    try$(testCase("height", "10px", "10px"));
    try$(testCase("min-width", "auto", "auto"));
    try$(testCase("min-height", "10%", "10%"));
    try$(testCase("max-width", "10%", "10%"));
    try$(testCase("max-height", "calc(10% + 40px)", "calc(10% + 40px)"));
    try$(testCase("box-sizing", "border-box", "border-box"));
    try$(testCase("display", "block", "block"));
    try$(testCase("display", "contents", "contents"));
    try$(testCase("display", "block list-item", "list-item"));
    try$(testCase("display", "table", "table"));
    try$(testCase("display", "inline-table", "inline-table"));
    try$(testCase("color", "#234", "rgb(34, 51, 68)"));
    try$(testCase("color", "hsl(120, 100%, 50%)", "rgb(0, 255, 0)"));
    try$(testCase("background-color", "rgb(0, 0, 255)", "rgb(0, 0, 255)"));

    // Margin & Padding
    try$(testCase("margin-inline-start", "auto", "auto"));
    try$(testCase("margin-inline-end", "5%", "5%"));
    try$(testCase("margin-block-start", "calc(10% - 2em)", "calc(10% - 2em)"));
    try$(testCase("margin-block-end", "-10px", "-10px"));
    try$(testCase("padding-inline-start", "4px", "4px"));
    try$(testCase("padding-inline-end", "10%", "10%"));
    try$(testCase("margin-top", "-10px", "-10px"));
    try$(testCase("margin-right", "20%", "20%"));
    try$(testCase("margin-bottom", "calc(2em + 3ex)", "calc(2em + 3ex)"));
    try$(testCase("margin-left", "auto", "auto"));
    try$(testCase("padding-top", "10px", "10px"));
    try$(testCase("padding-right", "20%", "20%"));
    try$(testCase("padding-bottom", "30px", "30px"));
    try$(testCase("padding-left", "40px", "40px"));

    // Positioned
    try$(testCase("top", "auto", "auto"));
    try$(testCase("right", "10px", "10px"));
    try$(testCase("bottom", "20%", "20%"));
    try$(testCase("left", "calc(1em + 2px)", "calc(1em + 2px)"));
    try$(testCase("z-index", "auto", "auto"));
    try$(testCase("z-index", "-1", "-1"));

    // Flex & Gaps
    try$(testCase("flex-basis", "content", "content"));
    try$(testCase("flex-basis", "10px", "10px"));
    try$(testCase("flex-grow", "2", "2"));
    try$(testCase("flex-shrink", "0", "0"));
    try$(testCase("flex-direction", "row-reverse", "row-reverse"));
    try$(testCase("flex-wrap", "wrap-reverse", "wrap-reverse"));
    try$(testCase("row-gap", "normal", "normal"));
    try$(testCase("column-gap", "10px", "10px"));

    // Box Alignment
    try$(testCase("align-items", "center", "center"));
    try$(testCase("align-items", "first-baseline", "baseline"));
    try$(testCase("align-items", "last-baseline", "last baseline"));
    try$(testCase("align-self", "auto", "auto"));
    try$(testCase("align-content", "space-evenly", "space-evenly"));
    try$(testCase("justify-content", "safe center", "safe center"));
    try$(testCase("justify-items", "legacy left", "legacy left"));
    try$(testCase("justify-items", "legacy", "legacy"));
    try$(testCase("justify-content", "unsafe end", "unsafe end"));
    try$(testCase("justify-self", "flex-end", "flex-end"));

    // Borders & Outline
    try$(testCase("border-top-color", "red", "rgb(255, 0, 0)"));
    try$(testCase("border-right-color", "red", "rgb(255, 0, 0)"));
    try$(testCase("border-bottom-color", "red", "rgb(255, 0, 0)"));
    try$(testCase("border-left-color", "red", "rgb(255, 0, 0)"));
    try$(testCase("border-top-style", "solid", "solid"));
    try$(testCase("border-right-style", "dotted", "dotted"));
    try$(testCase("border-bottom-style", "double", "double"));
    try$(testCase("border-left-style", "none", "none"));
    try$(testCase("outline-width", "thin", "thin"));
    try$(testCase("outline-width", "3px", "3px"));
    try$(testCase("outline-offset", "2px", "2px"));
    try$(testCase("outline-style", "auto", "auto"));
    try$(testCase("outline-style", "dashed", "dashed"));
    try$(testCase("border-top-width", "0px", "0px"));
    try$(testCase("border-right-width", "thin", "thin"));
    try$(testCase("border-bottom-width", "5px", "5px"));
    try$(testCase("border-left-width", "thick", "thick"));
    try$(testCase("border-top-left-radius", "40px 0px", "40px 0px"));
    try$(testCase("border-top-right-radius", "10px 20px", "10px 20px"));
    try$(testCase("border-bottom-left-radius", "50% 60px", "50% 60px"));
    try$(testCase("border-bottom-right-radius", "30px 40%", "30px 40%"));
    try$(testCase("outline-color", "auto", "auto"));
    try$(testCase("outline-color", "red", "rgb(255, 0, 0)"));

    // Baseline
    try$(testCase("line-height", "normal", "normal"));
    try$(testCase("line-height", "2", "2"));
    try$(testCase("line-height", "120%", "120%"));
    try$(testCase("baseline-source", "first", "first"));
    try$(testCase("dominant-baseline", "text-bottom", "text-bottom"));
    try$(testCase("alignment-baseline", "middle", "middle"));
    try$(testCase("baseline-shift", "sub", "sub"));
    try$(testCase("baseline-shift", "5px", "5px"));

    // Fonts
    try$(testCase("font-weight", "bold", "700"));
    try$(testCase("font-weight", "100", "100"));
    try$(testCase("font-weight", "bolder", "bolder"));
    try$(testCase("font-width", "condensed", "75%"));
    try$(testCase("font-width", "120%", "120%"));
    try$(testCase("font-style", "normal", "normal"));
    try$(testCase("font-style", "italic", "italic"));
    try$(testCase("font-style", "oblique", "oblique"));
    try$(testCase("font-style", "oblique 10deg", "oblique 10deg"));
    try$(testCase("font-style", "oblique 10grad", "oblique 9deg"));
    try$(testCase("font-style", "oblique 0deg", "normal"));
    try$(testCase("font-family", "Helvetica, Verdana, sans-serif", "Helvetica, Verdana, sans-serif"));
    try$(testCase("font-size", "large", "large"));
    try$(testCase("font-size", "20%", "20%"));

    // Lists, Transforms & Visibility
    try$(testCase("list-style-position", "inside", "inside"));
    try$(testCase("transform-box", "stroke-box", "stroke-box"));
    try$(testCase("transform-box", "view-box", "view-box"));
    try$(testCase("transform-origin", "left top", "left top"));
    try$(testCase("transform-origin", "10px 20%", "10px 20%"));
    try$(testCase("opacity", "1", "1"));
    try$(testCase("visibility", "collapse", "collapse"));

    // SVG
    try$(testCase("fill", "none", "none"));
    try$(testCase("fill", "red", "rgb(255, 0, 0)"));
    try$(testCase("stroke", "rgb(12, 34, 56)", "rgb(12, 34, 56)"));
    try$(testCase("d", "path('M 10 2 H 20')", "path(\"M 10 2 H 20\")"));
    try$(testCase("viewbox", "0 0 100 50", "0 0 100 50"));
    try$(testCase("viewbox", "0,0,100,50", "0 0 100 50"));
    try$(testCase("fill-opacity", "1", "1"));
    try$(testCase("stroke-opacity", "0", "0"));
    try$(testCase("x", "10px", "10px"));
    try$(testCase("y", "5%", "5%"));
    try$(testCase("cx", "1px", "1px"));
    try$(testCase("cy", "2px", "2px"));
    try$(testCase("r", "3px", "3px"));
    try$(testCase("stroke-width", "2px", "2px"));

    // Floats & Overflow
    try$(testCase("float", "inline-start", "inline-start"));
    try$(testCase("clear", "both", "both"));
    try$(testCase("overflow-x", "hidden", "hidden"));
    try$(testCase("overflow-y", "scroll", "scroll"));
    try$(testCase("overflow-block", "auto", "auto"));
    try$(testCase("overflow-inline", "visible", "visible"));

    // Text, Breaks & Tables
    try$(testCase("text-align", "center", "center"));
    try$(testCase("text-align", "-webkit-center", "-vaev-block-center"));
    try$(testCase("white-space", "pre-wrap", "pre-wrap"));
    try$(testCase("text-transform", "uppercase", "uppercase"));
    try$(testCase("break-after", "page", "page"));
    try$(testCase("break-before", "avoid-column", "avoid-column"));
    try$(testCase("break-inside", "avoid-page", "avoid-page"));
    try$(testCase("table-layout", "fixed", "fixed"));
    try$(testCase("caption-side", "bottom", "bottom"));
    try$(testCase("border-collapse", "collapse", "collapse"));
    try$(testCase("border-spacing", "10px 20px", "10px 20px"));
    try$(testCase("border-spacing", "0px", "0px"));

    return Ok();
}

test$("vaev-style-serialize-initial-values") {
    auto registry = defaultRegistry();

    auto testCase = [&](Str name, Str expected) -> Res<> {
        auto registration = try$(registry.resolveRegistration(name, {}));
        Io::StringWriter w;
        try$(registration->initial()->serialize(w));
        assertEq$(w.take(), expected);
        return Ok();
    };

    try$(testCase("viewbox", ""));
    try$(testCase("d", "none"));
    return Ok();
}

test$("vaev-style-serialize-special-props") {
    auto registry = defaultRegistry();

    auto testCase = [&](Str name, Str input, Str expected) -> Res<> {
        auto prop = try$(registry.parseValue(Symbol::from(name), input, RegisteredPropertySet::TOP_LEVEL));
        Io::StringWriter w;
        try$(prop->serialize(w));
        assertEq$(w.take(), expected);
        return Ok();
    };

    try$(testCase("width", "inherit", "inherit"));
    try$(testCase("float", "initial", "initial"));
    try$(testCase("width", "var(--size)", "var(--size)"));
    try$(testCase("float", "toggle(left, right)", "toggle(left, right)"));
    try$(testCase("--size", "10px", "10px"));
    return Ok();
}

} // namespace Vaev::Style::Tests
