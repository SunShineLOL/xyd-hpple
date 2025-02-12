Pod::Spec.new do |s|
  s.name         = "xyd-hpple"
  s.version      = "0.5.1"
  s.summary      = "A nice Objective-C wrapper on the XPathQuery library for parsing HTML."
  s.homepage     = "https://github.com/SunShineLOL/xyd-hpple"
  s.license      = 'MIT'
  s.author       = "topfunky"
  s.ios.deployment_target = '9.0'
  s.osx.deployment_target = '10.9'
  s.source       = { :git => "https://github.com/SunShineLOL/xyd-hpple.git", :tag => s.version.to_s }
  s.source_files  = 'Pod/Classes', 'Pod/Classes/**/*.{h,m}'
  s.library = 'xml2'
  s.xcconfig = { 'HEADER_SEARCH_PATHS' => '$(SDKROOT)/usr/include/libxml2' }
  s.requires_arc = true
  s.module_name = "xyd_hpple"
end
