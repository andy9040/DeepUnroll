; ModuleID = 'test.ll'
source_filename = "test.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@stdout = external global ptr, align 8
@.str.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @foo(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %3)
  ret i32 1
}

declare i32 @printf(ptr noundef, ...) #1

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @bar(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %3)
  ret i32 2
}

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca [1000 x i32], align 16
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 0, ptr %1, align 4
  %5 = call i32 @foo(i32 noundef 24)
  store i32 0, ptr %3, align 4
  br label %6

6:                                                ; preds = %1084, %0
  %7 = load i32, ptr %3, align 4
  %8 = icmp slt i32 %7, 1000
  br i1 %8, label %9, label %1087

9:                                                ; preds = %6
  %10 = load i32, ptr %3, align 4
  %11 = sext i32 %10 to i64
  %12 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %11
  store i32 0, ptr %12, align 4
  br label %13

13:                                               ; preds = %9
  %14 = load i32, ptr %3, align 4
  %15 = add nsw i32 %14, 1
  store i32 %15, ptr %3, align 4
  %16 = load i32, ptr %3, align 4
  %17 = icmp slt i32 %16, 1000
  br i1 %17, label %18, label %1087

18:                                               ; preds = %13
  %19 = load i32, ptr %3, align 4
  %20 = sext i32 %19 to i64
  %21 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %20
  store i32 0, ptr %21, align 4
  br label %22

22:                                               ; preds = %18
  %23 = load i32, ptr %3, align 4
  %24 = add nsw i32 %23, 1
  store i32 %24, ptr %3, align 4
  %25 = load i32, ptr %3, align 4
  %26 = icmp slt i32 %25, 1000
  br i1 %26, label %27, label %1087

27:                                               ; preds = %22
  %28 = load i32, ptr %3, align 4
  %29 = sext i32 %28 to i64
  %30 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %29
  store i32 0, ptr %30, align 4
  br label %31

31:                                               ; preds = %27
  %32 = load i32, ptr %3, align 4
  %33 = add nsw i32 %32, 1
  store i32 %33, ptr %3, align 4
  %34 = load i32, ptr %3, align 4
  %35 = icmp slt i32 %34, 1000
  br i1 %35, label %36, label %1087

36:                                               ; preds = %31
  %37 = load i32, ptr %3, align 4
  %38 = sext i32 %37 to i64
  %39 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %38
  store i32 0, ptr %39, align 4
  br label %40

40:                                               ; preds = %36
  %41 = load i32, ptr %3, align 4
  %42 = add nsw i32 %41, 1
  store i32 %42, ptr %3, align 4
  %43 = load i32, ptr %3, align 4
  %44 = icmp slt i32 %43, 1000
  br i1 %44, label %45, label %1087

45:                                               ; preds = %40
  %46 = load i32, ptr %3, align 4
  %47 = sext i32 %46 to i64
  %48 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %47
  store i32 0, ptr %48, align 4
  br label %49

49:                                               ; preds = %45
  %50 = load i32, ptr %3, align 4
  %51 = add nsw i32 %50, 1
  store i32 %51, ptr %3, align 4
  %52 = load i32, ptr %3, align 4
  %53 = icmp slt i32 %52, 1000
  br i1 %53, label %54, label %1087

54:                                               ; preds = %49
  %55 = load i32, ptr %3, align 4
  %56 = sext i32 %55 to i64
  %57 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %56
  store i32 0, ptr %57, align 4
  br label %58

58:                                               ; preds = %54
  %59 = load i32, ptr %3, align 4
  %60 = add nsw i32 %59, 1
  store i32 %60, ptr %3, align 4
  %61 = load i32, ptr %3, align 4
  %62 = icmp slt i32 %61, 1000
  br i1 %62, label %63, label %1087

63:                                               ; preds = %58
  %64 = load i32, ptr %3, align 4
  %65 = sext i32 %64 to i64
  %66 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %65
  store i32 0, ptr %66, align 4
  br label %67

67:                                               ; preds = %63
  %68 = load i32, ptr %3, align 4
  %69 = add nsw i32 %68, 1
  store i32 %69, ptr %3, align 4
  %70 = load i32, ptr %3, align 4
  %71 = icmp slt i32 %70, 1000
  br i1 %71, label %72, label %1087

72:                                               ; preds = %67
  %73 = load i32, ptr %3, align 4
  %74 = sext i32 %73 to i64
  %75 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %74
  store i32 0, ptr %75, align 4
  br label %76

76:                                               ; preds = %72
  %77 = load i32, ptr %3, align 4
  %78 = add nsw i32 %77, 1
  store i32 %78, ptr %3, align 4
  %79 = load i32, ptr %3, align 4
  %80 = icmp slt i32 %79, 1000
  br i1 %80, label %81, label %1087

81:                                               ; preds = %76
  %82 = load i32, ptr %3, align 4
  %83 = sext i32 %82 to i64
  %84 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %83
  store i32 0, ptr %84, align 4
  br label %85

85:                                               ; preds = %81
  %86 = load i32, ptr %3, align 4
  %87 = add nsw i32 %86, 1
  store i32 %87, ptr %3, align 4
  %88 = load i32, ptr %3, align 4
  %89 = icmp slt i32 %88, 1000
  br i1 %89, label %90, label %1087

90:                                               ; preds = %85
  %91 = load i32, ptr %3, align 4
  %92 = sext i32 %91 to i64
  %93 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %92
  store i32 0, ptr %93, align 4
  br label %94

94:                                               ; preds = %90
  %95 = load i32, ptr %3, align 4
  %96 = add nsw i32 %95, 1
  store i32 %96, ptr %3, align 4
  %97 = load i32, ptr %3, align 4
  %98 = icmp slt i32 %97, 1000
  br i1 %98, label %99, label %1087

99:                                               ; preds = %94
  %100 = load i32, ptr %3, align 4
  %101 = sext i32 %100 to i64
  %102 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %101
  store i32 0, ptr %102, align 4
  br label %103

103:                                              ; preds = %99
  %104 = load i32, ptr %3, align 4
  %105 = add nsw i32 %104, 1
  store i32 %105, ptr %3, align 4
  %106 = load i32, ptr %3, align 4
  %107 = icmp slt i32 %106, 1000
  br i1 %107, label %108, label %1087

108:                                              ; preds = %103
  %109 = load i32, ptr %3, align 4
  %110 = sext i32 %109 to i64
  %111 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %110
  store i32 0, ptr %111, align 4
  br label %112

112:                                              ; preds = %108
  %113 = load i32, ptr %3, align 4
  %114 = add nsw i32 %113, 1
  store i32 %114, ptr %3, align 4
  %115 = load i32, ptr %3, align 4
  %116 = icmp slt i32 %115, 1000
  br i1 %116, label %117, label %1087

117:                                              ; preds = %112
  %118 = load i32, ptr %3, align 4
  %119 = sext i32 %118 to i64
  %120 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %119
  store i32 0, ptr %120, align 4
  br label %121

121:                                              ; preds = %117
  %122 = load i32, ptr %3, align 4
  %123 = add nsw i32 %122, 1
  store i32 %123, ptr %3, align 4
  %124 = load i32, ptr %3, align 4
  %125 = icmp slt i32 %124, 1000
  br i1 %125, label %126, label %1087

126:                                              ; preds = %121
  %127 = load i32, ptr %3, align 4
  %128 = sext i32 %127 to i64
  %129 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %128
  store i32 0, ptr %129, align 4
  br label %130

130:                                              ; preds = %126
  %131 = load i32, ptr %3, align 4
  %132 = add nsw i32 %131, 1
  store i32 %132, ptr %3, align 4
  %133 = load i32, ptr %3, align 4
  %134 = icmp slt i32 %133, 1000
  br i1 %134, label %135, label %1087

135:                                              ; preds = %130
  %136 = load i32, ptr %3, align 4
  %137 = sext i32 %136 to i64
  %138 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %137
  store i32 0, ptr %138, align 4
  br label %139

139:                                              ; preds = %135
  %140 = load i32, ptr %3, align 4
  %141 = add nsw i32 %140, 1
  store i32 %141, ptr %3, align 4
  %142 = load i32, ptr %3, align 4
  %143 = icmp slt i32 %142, 1000
  br i1 %143, label %144, label %1087

144:                                              ; preds = %139
  %145 = load i32, ptr %3, align 4
  %146 = sext i32 %145 to i64
  %147 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %146
  store i32 0, ptr %147, align 4
  br label %148

148:                                              ; preds = %144
  %149 = load i32, ptr %3, align 4
  %150 = add nsw i32 %149, 1
  store i32 %150, ptr %3, align 4
  %151 = load i32, ptr %3, align 4
  %152 = icmp slt i32 %151, 1000
  br i1 %152, label %153, label %1087

153:                                              ; preds = %148
  %154 = load i32, ptr %3, align 4
  %155 = sext i32 %154 to i64
  %156 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %155
  store i32 0, ptr %156, align 4
  br label %157

157:                                              ; preds = %153
  %158 = load i32, ptr %3, align 4
  %159 = add nsw i32 %158, 1
  store i32 %159, ptr %3, align 4
  %160 = load i32, ptr %3, align 4
  %161 = icmp slt i32 %160, 1000
  br i1 %161, label %162, label %1087

162:                                              ; preds = %157
  %163 = load i32, ptr %3, align 4
  %164 = sext i32 %163 to i64
  %165 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %164
  store i32 0, ptr %165, align 4
  br label %166

166:                                              ; preds = %162
  %167 = load i32, ptr %3, align 4
  %168 = add nsw i32 %167, 1
  store i32 %168, ptr %3, align 4
  %169 = load i32, ptr %3, align 4
  %170 = icmp slt i32 %169, 1000
  br i1 %170, label %171, label %1087

171:                                              ; preds = %166
  %172 = load i32, ptr %3, align 4
  %173 = sext i32 %172 to i64
  %174 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %173
  store i32 0, ptr %174, align 4
  br label %175

175:                                              ; preds = %171
  %176 = load i32, ptr %3, align 4
  %177 = add nsw i32 %176, 1
  store i32 %177, ptr %3, align 4
  %178 = load i32, ptr %3, align 4
  %179 = icmp slt i32 %178, 1000
  br i1 %179, label %180, label %1087

180:                                              ; preds = %175
  %181 = load i32, ptr %3, align 4
  %182 = sext i32 %181 to i64
  %183 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %182
  store i32 0, ptr %183, align 4
  br label %184

184:                                              ; preds = %180
  %185 = load i32, ptr %3, align 4
  %186 = add nsw i32 %185, 1
  store i32 %186, ptr %3, align 4
  %187 = load i32, ptr %3, align 4
  %188 = icmp slt i32 %187, 1000
  br i1 %188, label %189, label %1087

189:                                              ; preds = %184
  %190 = load i32, ptr %3, align 4
  %191 = sext i32 %190 to i64
  %192 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %191
  store i32 0, ptr %192, align 4
  br label %193

193:                                              ; preds = %189
  %194 = load i32, ptr %3, align 4
  %195 = add nsw i32 %194, 1
  store i32 %195, ptr %3, align 4
  %196 = load i32, ptr %3, align 4
  %197 = icmp slt i32 %196, 1000
  br i1 %197, label %198, label %1087

198:                                              ; preds = %193
  %199 = load i32, ptr %3, align 4
  %200 = sext i32 %199 to i64
  %201 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %200
  store i32 0, ptr %201, align 4
  br label %202

202:                                              ; preds = %198
  %203 = load i32, ptr %3, align 4
  %204 = add nsw i32 %203, 1
  store i32 %204, ptr %3, align 4
  %205 = load i32, ptr %3, align 4
  %206 = icmp slt i32 %205, 1000
  br i1 %206, label %207, label %1087

207:                                              ; preds = %202
  %208 = load i32, ptr %3, align 4
  %209 = sext i32 %208 to i64
  %210 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %209
  store i32 0, ptr %210, align 4
  br label %211

211:                                              ; preds = %207
  %212 = load i32, ptr %3, align 4
  %213 = add nsw i32 %212, 1
  store i32 %213, ptr %3, align 4
  %214 = load i32, ptr %3, align 4
  %215 = icmp slt i32 %214, 1000
  br i1 %215, label %216, label %1087

216:                                              ; preds = %211
  %217 = load i32, ptr %3, align 4
  %218 = sext i32 %217 to i64
  %219 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %218
  store i32 0, ptr %219, align 4
  br label %220

220:                                              ; preds = %216
  %221 = load i32, ptr %3, align 4
  %222 = add nsw i32 %221, 1
  store i32 %222, ptr %3, align 4
  %223 = load i32, ptr %3, align 4
  %224 = icmp slt i32 %223, 1000
  br i1 %224, label %225, label %1087

225:                                              ; preds = %220
  %226 = load i32, ptr %3, align 4
  %227 = sext i32 %226 to i64
  %228 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %227
  store i32 0, ptr %228, align 4
  br label %229

229:                                              ; preds = %225
  %230 = load i32, ptr %3, align 4
  %231 = add nsw i32 %230, 1
  store i32 %231, ptr %3, align 4
  %232 = load i32, ptr %3, align 4
  %233 = icmp slt i32 %232, 1000
  br i1 %233, label %234, label %1087

234:                                              ; preds = %229
  %235 = load i32, ptr %3, align 4
  %236 = sext i32 %235 to i64
  %237 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %236
  store i32 0, ptr %237, align 4
  br label %238

238:                                              ; preds = %234
  %239 = load i32, ptr %3, align 4
  %240 = add nsw i32 %239, 1
  store i32 %240, ptr %3, align 4
  %241 = load i32, ptr %3, align 4
  %242 = icmp slt i32 %241, 1000
  br i1 %242, label %243, label %1087

243:                                              ; preds = %238
  %244 = load i32, ptr %3, align 4
  %245 = sext i32 %244 to i64
  %246 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %245
  store i32 0, ptr %246, align 4
  br label %247

247:                                              ; preds = %243
  %248 = load i32, ptr %3, align 4
  %249 = add nsw i32 %248, 1
  store i32 %249, ptr %3, align 4
  %250 = load i32, ptr %3, align 4
  %251 = icmp slt i32 %250, 1000
  br i1 %251, label %252, label %1087

252:                                              ; preds = %247
  %253 = load i32, ptr %3, align 4
  %254 = sext i32 %253 to i64
  %255 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %254
  store i32 0, ptr %255, align 4
  br label %256

256:                                              ; preds = %252
  %257 = load i32, ptr %3, align 4
  %258 = add nsw i32 %257, 1
  store i32 %258, ptr %3, align 4
  %259 = load i32, ptr %3, align 4
  %260 = icmp slt i32 %259, 1000
  br i1 %260, label %261, label %1087

261:                                              ; preds = %256
  %262 = load i32, ptr %3, align 4
  %263 = sext i32 %262 to i64
  %264 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %263
  store i32 0, ptr %264, align 4
  br label %265

265:                                              ; preds = %261
  %266 = load i32, ptr %3, align 4
  %267 = add nsw i32 %266, 1
  store i32 %267, ptr %3, align 4
  %268 = load i32, ptr %3, align 4
  %269 = icmp slt i32 %268, 1000
  br i1 %269, label %270, label %1087

270:                                              ; preds = %265
  %271 = load i32, ptr %3, align 4
  %272 = sext i32 %271 to i64
  %273 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %272
  store i32 0, ptr %273, align 4
  br label %274

274:                                              ; preds = %270
  %275 = load i32, ptr %3, align 4
  %276 = add nsw i32 %275, 1
  store i32 %276, ptr %3, align 4
  %277 = load i32, ptr %3, align 4
  %278 = icmp slt i32 %277, 1000
  br i1 %278, label %279, label %1087

279:                                              ; preds = %274
  %280 = load i32, ptr %3, align 4
  %281 = sext i32 %280 to i64
  %282 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %281
  store i32 0, ptr %282, align 4
  br label %283

283:                                              ; preds = %279
  %284 = load i32, ptr %3, align 4
  %285 = add nsw i32 %284, 1
  store i32 %285, ptr %3, align 4
  %286 = load i32, ptr %3, align 4
  %287 = icmp slt i32 %286, 1000
  br i1 %287, label %288, label %1087

288:                                              ; preds = %283
  %289 = load i32, ptr %3, align 4
  %290 = sext i32 %289 to i64
  %291 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %290
  store i32 0, ptr %291, align 4
  br label %292

292:                                              ; preds = %288
  %293 = load i32, ptr %3, align 4
  %294 = add nsw i32 %293, 1
  store i32 %294, ptr %3, align 4
  %295 = load i32, ptr %3, align 4
  %296 = icmp slt i32 %295, 1000
  br i1 %296, label %297, label %1087

297:                                              ; preds = %292
  %298 = load i32, ptr %3, align 4
  %299 = sext i32 %298 to i64
  %300 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %299
  store i32 0, ptr %300, align 4
  br label %301

301:                                              ; preds = %297
  %302 = load i32, ptr %3, align 4
  %303 = add nsw i32 %302, 1
  store i32 %303, ptr %3, align 4
  %304 = load i32, ptr %3, align 4
  %305 = icmp slt i32 %304, 1000
  br i1 %305, label %306, label %1087

306:                                              ; preds = %301
  %307 = load i32, ptr %3, align 4
  %308 = sext i32 %307 to i64
  %309 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %308
  store i32 0, ptr %309, align 4
  br label %310

310:                                              ; preds = %306
  %311 = load i32, ptr %3, align 4
  %312 = add nsw i32 %311, 1
  store i32 %312, ptr %3, align 4
  %313 = load i32, ptr %3, align 4
  %314 = icmp slt i32 %313, 1000
  br i1 %314, label %315, label %1087

315:                                              ; preds = %310
  %316 = load i32, ptr %3, align 4
  %317 = sext i32 %316 to i64
  %318 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %317
  store i32 0, ptr %318, align 4
  br label %319

319:                                              ; preds = %315
  %320 = load i32, ptr %3, align 4
  %321 = add nsw i32 %320, 1
  store i32 %321, ptr %3, align 4
  %322 = load i32, ptr %3, align 4
  %323 = icmp slt i32 %322, 1000
  br i1 %323, label %324, label %1087

324:                                              ; preds = %319
  %325 = load i32, ptr %3, align 4
  %326 = sext i32 %325 to i64
  %327 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %326
  store i32 0, ptr %327, align 4
  br label %328

328:                                              ; preds = %324
  %329 = load i32, ptr %3, align 4
  %330 = add nsw i32 %329, 1
  store i32 %330, ptr %3, align 4
  %331 = load i32, ptr %3, align 4
  %332 = icmp slt i32 %331, 1000
  br i1 %332, label %333, label %1087

333:                                              ; preds = %328
  %334 = load i32, ptr %3, align 4
  %335 = sext i32 %334 to i64
  %336 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %335
  store i32 0, ptr %336, align 4
  br label %337

337:                                              ; preds = %333
  %338 = load i32, ptr %3, align 4
  %339 = add nsw i32 %338, 1
  store i32 %339, ptr %3, align 4
  %340 = load i32, ptr %3, align 4
  %341 = icmp slt i32 %340, 1000
  br i1 %341, label %342, label %1087

342:                                              ; preds = %337
  %343 = load i32, ptr %3, align 4
  %344 = sext i32 %343 to i64
  %345 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %344
  store i32 0, ptr %345, align 4
  br label %346

346:                                              ; preds = %342
  %347 = load i32, ptr %3, align 4
  %348 = add nsw i32 %347, 1
  store i32 %348, ptr %3, align 4
  %349 = load i32, ptr %3, align 4
  %350 = icmp slt i32 %349, 1000
  br i1 %350, label %351, label %1087

351:                                              ; preds = %346
  %352 = load i32, ptr %3, align 4
  %353 = sext i32 %352 to i64
  %354 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %353
  store i32 0, ptr %354, align 4
  br label %355

355:                                              ; preds = %351
  %356 = load i32, ptr %3, align 4
  %357 = add nsw i32 %356, 1
  store i32 %357, ptr %3, align 4
  %358 = load i32, ptr %3, align 4
  %359 = icmp slt i32 %358, 1000
  br i1 %359, label %360, label %1087

360:                                              ; preds = %355
  %361 = load i32, ptr %3, align 4
  %362 = sext i32 %361 to i64
  %363 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %362
  store i32 0, ptr %363, align 4
  br label %364

364:                                              ; preds = %360
  %365 = load i32, ptr %3, align 4
  %366 = add nsw i32 %365, 1
  store i32 %366, ptr %3, align 4
  %367 = load i32, ptr %3, align 4
  %368 = icmp slt i32 %367, 1000
  br i1 %368, label %369, label %1087

369:                                              ; preds = %364
  %370 = load i32, ptr %3, align 4
  %371 = sext i32 %370 to i64
  %372 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %371
  store i32 0, ptr %372, align 4
  br label %373

373:                                              ; preds = %369
  %374 = load i32, ptr %3, align 4
  %375 = add nsw i32 %374, 1
  store i32 %375, ptr %3, align 4
  %376 = load i32, ptr %3, align 4
  %377 = icmp slt i32 %376, 1000
  br i1 %377, label %378, label %1087

378:                                              ; preds = %373
  %379 = load i32, ptr %3, align 4
  %380 = sext i32 %379 to i64
  %381 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %380
  store i32 0, ptr %381, align 4
  br label %382

382:                                              ; preds = %378
  %383 = load i32, ptr %3, align 4
  %384 = add nsw i32 %383, 1
  store i32 %384, ptr %3, align 4
  %385 = load i32, ptr %3, align 4
  %386 = icmp slt i32 %385, 1000
  br i1 %386, label %387, label %1087

387:                                              ; preds = %382
  %388 = load i32, ptr %3, align 4
  %389 = sext i32 %388 to i64
  %390 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %389
  store i32 0, ptr %390, align 4
  br label %391

391:                                              ; preds = %387
  %392 = load i32, ptr %3, align 4
  %393 = add nsw i32 %392, 1
  store i32 %393, ptr %3, align 4
  %394 = load i32, ptr %3, align 4
  %395 = icmp slt i32 %394, 1000
  br i1 %395, label %396, label %1087

396:                                              ; preds = %391
  %397 = load i32, ptr %3, align 4
  %398 = sext i32 %397 to i64
  %399 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %398
  store i32 0, ptr %399, align 4
  br label %400

400:                                              ; preds = %396
  %401 = load i32, ptr %3, align 4
  %402 = add nsw i32 %401, 1
  store i32 %402, ptr %3, align 4
  %403 = load i32, ptr %3, align 4
  %404 = icmp slt i32 %403, 1000
  br i1 %404, label %405, label %1087

405:                                              ; preds = %400
  %406 = load i32, ptr %3, align 4
  %407 = sext i32 %406 to i64
  %408 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %407
  store i32 0, ptr %408, align 4
  br label %409

409:                                              ; preds = %405
  %410 = load i32, ptr %3, align 4
  %411 = add nsw i32 %410, 1
  store i32 %411, ptr %3, align 4
  %412 = load i32, ptr %3, align 4
  %413 = icmp slt i32 %412, 1000
  br i1 %413, label %414, label %1087

414:                                              ; preds = %409
  %415 = load i32, ptr %3, align 4
  %416 = sext i32 %415 to i64
  %417 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %416
  store i32 0, ptr %417, align 4
  br label %418

418:                                              ; preds = %414
  %419 = load i32, ptr %3, align 4
  %420 = add nsw i32 %419, 1
  store i32 %420, ptr %3, align 4
  %421 = load i32, ptr %3, align 4
  %422 = icmp slt i32 %421, 1000
  br i1 %422, label %423, label %1087

423:                                              ; preds = %418
  %424 = load i32, ptr %3, align 4
  %425 = sext i32 %424 to i64
  %426 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %425
  store i32 0, ptr %426, align 4
  br label %427

427:                                              ; preds = %423
  %428 = load i32, ptr %3, align 4
  %429 = add nsw i32 %428, 1
  store i32 %429, ptr %3, align 4
  %430 = load i32, ptr %3, align 4
  %431 = icmp slt i32 %430, 1000
  br i1 %431, label %432, label %1087

432:                                              ; preds = %427
  %433 = load i32, ptr %3, align 4
  %434 = sext i32 %433 to i64
  %435 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %434
  store i32 0, ptr %435, align 4
  br label %436

436:                                              ; preds = %432
  %437 = load i32, ptr %3, align 4
  %438 = add nsw i32 %437, 1
  store i32 %438, ptr %3, align 4
  %439 = load i32, ptr %3, align 4
  %440 = icmp slt i32 %439, 1000
  br i1 %440, label %441, label %1087

441:                                              ; preds = %436
  %442 = load i32, ptr %3, align 4
  %443 = sext i32 %442 to i64
  %444 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %443
  store i32 0, ptr %444, align 4
  br label %445

445:                                              ; preds = %441
  %446 = load i32, ptr %3, align 4
  %447 = add nsw i32 %446, 1
  store i32 %447, ptr %3, align 4
  %448 = load i32, ptr %3, align 4
  %449 = icmp slt i32 %448, 1000
  br i1 %449, label %450, label %1087

450:                                              ; preds = %445
  %451 = load i32, ptr %3, align 4
  %452 = sext i32 %451 to i64
  %453 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %452
  store i32 0, ptr %453, align 4
  br label %454

454:                                              ; preds = %450
  %455 = load i32, ptr %3, align 4
  %456 = add nsw i32 %455, 1
  store i32 %456, ptr %3, align 4
  %457 = load i32, ptr %3, align 4
  %458 = icmp slt i32 %457, 1000
  br i1 %458, label %459, label %1087

459:                                              ; preds = %454
  %460 = load i32, ptr %3, align 4
  %461 = sext i32 %460 to i64
  %462 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %461
  store i32 0, ptr %462, align 4
  br label %463

463:                                              ; preds = %459
  %464 = load i32, ptr %3, align 4
  %465 = add nsw i32 %464, 1
  store i32 %465, ptr %3, align 4
  %466 = load i32, ptr %3, align 4
  %467 = icmp slt i32 %466, 1000
  br i1 %467, label %468, label %1087

468:                                              ; preds = %463
  %469 = load i32, ptr %3, align 4
  %470 = sext i32 %469 to i64
  %471 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %470
  store i32 0, ptr %471, align 4
  br label %472

472:                                              ; preds = %468
  %473 = load i32, ptr %3, align 4
  %474 = add nsw i32 %473, 1
  store i32 %474, ptr %3, align 4
  %475 = load i32, ptr %3, align 4
  %476 = icmp slt i32 %475, 1000
  br i1 %476, label %477, label %1087

477:                                              ; preds = %472
  %478 = load i32, ptr %3, align 4
  %479 = sext i32 %478 to i64
  %480 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %479
  store i32 0, ptr %480, align 4
  br label %481

481:                                              ; preds = %477
  %482 = load i32, ptr %3, align 4
  %483 = add nsw i32 %482, 1
  store i32 %483, ptr %3, align 4
  %484 = load i32, ptr %3, align 4
  %485 = icmp slt i32 %484, 1000
  br i1 %485, label %486, label %1087

486:                                              ; preds = %481
  %487 = load i32, ptr %3, align 4
  %488 = sext i32 %487 to i64
  %489 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %488
  store i32 0, ptr %489, align 4
  br label %490

490:                                              ; preds = %486
  %491 = load i32, ptr %3, align 4
  %492 = add nsw i32 %491, 1
  store i32 %492, ptr %3, align 4
  %493 = load i32, ptr %3, align 4
  %494 = icmp slt i32 %493, 1000
  br i1 %494, label %495, label %1087

495:                                              ; preds = %490
  %496 = load i32, ptr %3, align 4
  %497 = sext i32 %496 to i64
  %498 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %497
  store i32 0, ptr %498, align 4
  br label %499

499:                                              ; preds = %495
  %500 = load i32, ptr %3, align 4
  %501 = add nsw i32 %500, 1
  store i32 %501, ptr %3, align 4
  %502 = load i32, ptr %3, align 4
  %503 = icmp slt i32 %502, 1000
  br i1 %503, label %504, label %1087

504:                                              ; preds = %499
  %505 = load i32, ptr %3, align 4
  %506 = sext i32 %505 to i64
  %507 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %506
  store i32 0, ptr %507, align 4
  br label %508

508:                                              ; preds = %504
  %509 = load i32, ptr %3, align 4
  %510 = add nsw i32 %509, 1
  store i32 %510, ptr %3, align 4
  %511 = load i32, ptr %3, align 4
  %512 = icmp slt i32 %511, 1000
  br i1 %512, label %513, label %1087

513:                                              ; preds = %508
  %514 = load i32, ptr %3, align 4
  %515 = sext i32 %514 to i64
  %516 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %515
  store i32 0, ptr %516, align 4
  br label %517

517:                                              ; preds = %513
  %518 = load i32, ptr %3, align 4
  %519 = add nsw i32 %518, 1
  store i32 %519, ptr %3, align 4
  %520 = load i32, ptr %3, align 4
  %521 = icmp slt i32 %520, 1000
  br i1 %521, label %522, label %1087

522:                                              ; preds = %517
  %523 = load i32, ptr %3, align 4
  %524 = sext i32 %523 to i64
  %525 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %524
  store i32 0, ptr %525, align 4
  br label %526

526:                                              ; preds = %522
  %527 = load i32, ptr %3, align 4
  %528 = add nsw i32 %527, 1
  store i32 %528, ptr %3, align 4
  %529 = load i32, ptr %3, align 4
  %530 = icmp slt i32 %529, 1000
  br i1 %530, label %531, label %1087

531:                                              ; preds = %526
  %532 = load i32, ptr %3, align 4
  %533 = sext i32 %532 to i64
  %534 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %533
  store i32 0, ptr %534, align 4
  br label %535

535:                                              ; preds = %531
  %536 = load i32, ptr %3, align 4
  %537 = add nsw i32 %536, 1
  store i32 %537, ptr %3, align 4
  %538 = load i32, ptr %3, align 4
  %539 = icmp slt i32 %538, 1000
  br i1 %539, label %540, label %1087

540:                                              ; preds = %535
  %541 = load i32, ptr %3, align 4
  %542 = sext i32 %541 to i64
  %543 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %542
  store i32 0, ptr %543, align 4
  br label %544

544:                                              ; preds = %540
  %545 = load i32, ptr %3, align 4
  %546 = add nsw i32 %545, 1
  store i32 %546, ptr %3, align 4
  %547 = load i32, ptr %3, align 4
  %548 = icmp slt i32 %547, 1000
  br i1 %548, label %549, label %1087

549:                                              ; preds = %544
  %550 = load i32, ptr %3, align 4
  %551 = sext i32 %550 to i64
  %552 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %551
  store i32 0, ptr %552, align 4
  br label %553

553:                                              ; preds = %549
  %554 = load i32, ptr %3, align 4
  %555 = add nsw i32 %554, 1
  store i32 %555, ptr %3, align 4
  %556 = load i32, ptr %3, align 4
  %557 = icmp slt i32 %556, 1000
  br i1 %557, label %558, label %1087

558:                                              ; preds = %553
  %559 = load i32, ptr %3, align 4
  %560 = sext i32 %559 to i64
  %561 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %560
  store i32 0, ptr %561, align 4
  br label %562

562:                                              ; preds = %558
  %563 = load i32, ptr %3, align 4
  %564 = add nsw i32 %563, 1
  store i32 %564, ptr %3, align 4
  %565 = load i32, ptr %3, align 4
  %566 = icmp slt i32 %565, 1000
  br i1 %566, label %567, label %1087

567:                                              ; preds = %562
  %568 = load i32, ptr %3, align 4
  %569 = sext i32 %568 to i64
  %570 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %569
  store i32 0, ptr %570, align 4
  br label %571

571:                                              ; preds = %567
  %572 = load i32, ptr %3, align 4
  %573 = add nsw i32 %572, 1
  store i32 %573, ptr %3, align 4
  %574 = load i32, ptr %3, align 4
  %575 = icmp slt i32 %574, 1000
  br i1 %575, label %576, label %1087

576:                                              ; preds = %571
  %577 = load i32, ptr %3, align 4
  %578 = sext i32 %577 to i64
  %579 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %578
  store i32 0, ptr %579, align 4
  br label %580

580:                                              ; preds = %576
  %581 = load i32, ptr %3, align 4
  %582 = add nsw i32 %581, 1
  store i32 %582, ptr %3, align 4
  %583 = load i32, ptr %3, align 4
  %584 = icmp slt i32 %583, 1000
  br i1 %584, label %585, label %1087

585:                                              ; preds = %580
  %586 = load i32, ptr %3, align 4
  %587 = sext i32 %586 to i64
  %588 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %587
  store i32 0, ptr %588, align 4
  br label %589

589:                                              ; preds = %585
  %590 = load i32, ptr %3, align 4
  %591 = add nsw i32 %590, 1
  store i32 %591, ptr %3, align 4
  %592 = load i32, ptr %3, align 4
  %593 = icmp slt i32 %592, 1000
  br i1 %593, label %594, label %1087

594:                                              ; preds = %589
  %595 = load i32, ptr %3, align 4
  %596 = sext i32 %595 to i64
  %597 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %596
  store i32 0, ptr %597, align 4
  br label %598

598:                                              ; preds = %594
  %599 = load i32, ptr %3, align 4
  %600 = add nsw i32 %599, 1
  store i32 %600, ptr %3, align 4
  %601 = load i32, ptr %3, align 4
  %602 = icmp slt i32 %601, 1000
  br i1 %602, label %603, label %1087

603:                                              ; preds = %598
  %604 = load i32, ptr %3, align 4
  %605 = sext i32 %604 to i64
  %606 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %605
  store i32 0, ptr %606, align 4
  br label %607

607:                                              ; preds = %603
  %608 = load i32, ptr %3, align 4
  %609 = add nsw i32 %608, 1
  store i32 %609, ptr %3, align 4
  %610 = load i32, ptr %3, align 4
  %611 = icmp slt i32 %610, 1000
  br i1 %611, label %612, label %1087

612:                                              ; preds = %607
  %613 = load i32, ptr %3, align 4
  %614 = sext i32 %613 to i64
  %615 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %614
  store i32 0, ptr %615, align 4
  br label %616

616:                                              ; preds = %612
  %617 = load i32, ptr %3, align 4
  %618 = add nsw i32 %617, 1
  store i32 %618, ptr %3, align 4
  %619 = load i32, ptr %3, align 4
  %620 = icmp slt i32 %619, 1000
  br i1 %620, label %621, label %1087

621:                                              ; preds = %616
  %622 = load i32, ptr %3, align 4
  %623 = sext i32 %622 to i64
  %624 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %623
  store i32 0, ptr %624, align 4
  br label %625

625:                                              ; preds = %621
  %626 = load i32, ptr %3, align 4
  %627 = add nsw i32 %626, 1
  store i32 %627, ptr %3, align 4
  %628 = load i32, ptr %3, align 4
  %629 = icmp slt i32 %628, 1000
  br i1 %629, label %630, label %1087

630:                                              ; preds = %625
  %631 = load i32, ptr %3, align 4
  %632 = sext i32 %631 to i64
  %633 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %632
  store i32 0, ptr %633, align 4
  br label %634

634:                                              ; preds = %630
  %635 = load i32, ptr %3, align 4
  %636 = add nsw i32 %635, 1
  store i32 %636, ptr %3, align 4
  %637 = load i32, ptr %3, align 4
  %638 = icmp slt i32 %637, 1000
  br i1 %638, label %639, label %1087

639:                                              ; preds = %634
  %640 = load i32, ptr %3, align 4
  %641 = sext i32 %640 to i64
  %642 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %641
  store i32 0, ptr %642, align 4
  br label %643

643:                                              ; preds = %639
  %644 = load i32, ptr %3, align 4
  %645 = add nsw i32 %644, 1
  store i32 %645, ptr %3, align 4
  %646 = load i32, ptr %3, align 4
  %647 = icmp slt i32 %646, 1000
  br i1 %647, label %648, label %1087

648:                                              ; preds = %643
  %649 = load i32, ptr %3, align 4
  %650 = sext i32 %649 to i64
  %651 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %650
  store i32 0, ptr %651, align 4
  br label %652

652:                                              ; preds = %648
  %653 = load i32, ptr %3, align 4
  %654 = add nsw i32 %653, 1
  store i32 %654, ptr %3, align 4
  %655 = load i32, ptr %3, align 4
  %656 = icmp slt i32 %655, 1000
  br i1 %656, label %657, label %1087

657:                                              ; preds = %652
  %658 = load i32, ptr %3, align 4
  %659 = sext i32 %658 to i64
  %660 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %659
  store i32 0, ptr %660, align 4
  br label %661

661:                                              ; preds = %657
  %662 = load i32, ptr %3, align 4
  %663 = add nsw i32 %662, 1
  store i32 %663, ptr %3, align 4
  %664 = load i32, ptr %3, align 4
  %665 = icmp slt i32 %664, 1000
  br i1 %665, label %666, label %1087

666:                                              ; preds = %661
  %667 = load i32, ptr %3, align 4
  %668 = sext i32 %667 to i64
  %669 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %668
  store i32 0, ptr %669, align 4
  br label %670

670:                                              ; preds = %666
  %671 = load i32, ptr %3, align 4
  %672 = add nsw i32 %671, 1
  store i32 %672, ptr %3, align 4
  %673 = load i32, ptr %3, align 4
  %674 = icmp slt i32 %673, 1000
  br i1 %674, label %675, label %1087

675:                                              ; preds = %670
  %676 = load i32, ptr %3, align 4
  %677 = sext i32 %676 to i64
  %678 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %677
  store i32 0, ptr %678, align 4
  br label %679

679:                                              ; preds = %675
  %680 = load i32, ptr %3, align 4
  %681 = add nsw i32 %680, 1
  store i32 %681, ptr %3, align 4
  %682 = load i32, ptr %3, align 4
  %683 = icmp slt i32 %682, 1000
  br i1 %683, label %684, label %1087

684:                                              ; preds = %679
  %685 = load i32, ptr %3, align 4
  %686 = sext i32 %685 to i64
  %687 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %686
  store i32 0, ptr %687, align 4
  br label %688

688:                                              ; preds = %684
  %689 = load i32, ptr %3, align 4
  %690 = add nsw i32 %689, 1
  store i32 %690, ptr %3, align 4
  %691 = load i32, ptr %3, align 4
  %692 = icmp slt i32 %691, 1000
  br i1 %692, label %693, label %1087

693:                                              ; preds = %688
  %694 = load i32, ptr %3, align 4
  %695 = sext i32 %694 to i64
  %696 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %695
  store i32 0, ptr %696, align 4
  br label %697

697:                                              ; preds = %693
  %698 = load i32, ptr %3, align 4
  %699 = add nsw i32 %698, 1
  store i32 %699, ptr %3, align 4
  %700 = load i32, ptr %3, align 4
  %701 = icmp slt i32 %700, 1000
  br i1 %701, label %702, label %1087

702:                                              ; preds = %697
  %703 = load i32, ptr %3, align 4
  %704 = sext i32 %703 to i64
  %705 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %704
  store i32 0, ptr %705, align 4
  br label %706

706:                                              ; preds = %702
  %707 = load i32, ptr %3, align 4
  %708 = add nsw i32 %707, 1
  store i32 %708, ptr %3, align 4
  %709 = load i32, ptr %3, align 4
  %710 = icmp slt i32 %709, 1000
  br i1 %710, label %711, label %1087

711:                                              ; preds = %706
  %712 = load i32, ptr %3, align 4
  %713 = sext i32 %712 to i64
  %714 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %713
  store i32 0, ptr %714, align 4
  br label %715

715:                                              ; preds = %711
  %716 = load i32, ptr %3, align 4
  %717 = add nsw i32 %716, 1
  store i32 %717, ptr %3, align 4
  %718 = load i32, ptr %3, align 4
  %719 = icmp slt i32 %718, 1000
  br i1 %719, label %720, label %1087

720:                                              ; preds = %715
  %721 = load i32, ptr %3, align 4
  %722 = sext i32 %721 to i64
  %723 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %722
  store i32 0, ptr %723, align 4
  br label %724

724:                                              ; preds = %720
  %725 = load i32, ptr %3, align 4
  %726 = add nsw i32 %725, 1
  store i32 %726, ptr %3, align 4
  %727 = load i32, ptr %3, align 4
  %728 = icmp slt i32 %727, 1000
  br i1 %728, label %729, label %1087

729:                                              ; preds = %724
  %730 = load i32, ptr %3, align 4
  %731 = sext i32 %730 to i64
  %732 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %731
  store i32 0, ptr %732, align 4
  br label %733

733:                                              ; preds = %729
  %734 = load i32, ptr %3, align 4
  %735 = add nsw i32 %734, 1
  store i32 %735, ptr %3, align 4
  %736 = load i32, ptr %3, align 4
  %737 = icmp slt i32 %736, 1000
  br i1 %737, label %738, label %1087

738:                                              ; preds = %733
  %739 = load i32, ptr %3, align 4
  %740 = sext i32 %739 to i64
  %741 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %740
  store i32 0, ptr %741, align 4
  br label %742

742:                                              ; preds = %738
  %743 = load i32, ptr %3, align 4
  %744 = add nsw i32 %743, 1
  store i32 %744, ptr %3, align 4
  %745 = load i32, ptr %3, align 4
  %746 = icmp slt i32 %745, 1000
  br i1 %746, label %747, label %1087

747:                                              ; preds = %742
  %748 = load i32, ptr %3, align 4
  %749 = sext i32 %748 to i64
  %750 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %749
  store i32 0, ptr %750, align 4
  br label %751

751:                                              ; preds = %747
  %752 = load i32, ptr %3, align 4
  %753 = add nsw i32 %752, 1
  store i32 %753, ptr %3, align 4
  %754 = load i32, ptr %3, align 4
  %755 = icmp slt i32 %754, 1000
  br i1 %755, label %756, label %1087

756:                                              ; preds = %751
  %757 = load i32, ptr %3, align 4
  %758 = sext i32 %757 to i64
  %759 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %758
  store i32 0, ptr %759, align 4
  br label %760

760:                                              ; preds = %756
  %761 = load i32, ptr %3, align 4
  %762 = add nsw i32 %761, 1
  store i32 %762, ptr %3, align 4
  %763 = load i32, ptr %3, align 4
  %764 = icmp slt i32 %763, 1000
  br i1 %764, label %765, label %1087

765:                                              ; preds = %760
  %766 = load i32, ptr %3, align 4
  %767 = sext i32 %766 to i64
  %768 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %767
  store i32 0, ptr %768, align 4
  br label %769

769:                                              ; preds = %765
  %770 = load i32, ptr %3, align 4
  %771 = add nsw i32 %770, 1
  store i32 %771, ptr %3, align 4
  %772 = load i32, ptr %3, align 4
  %773 = icmp slt i32 %772, 1000
  br i1 %773, label %774, label %1087

774:                                              ; preds = %769
  %775 = load i32, ptr %3, align 4
  %776 = sext i32 %775 to i64
  %777 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %776
  store i32 0, ptr %777, align 4
  br label %778

778:                                              ; preds = %774
  %779 = load i32, ptr %3, align 4
  %780 = add nsw i32 %779, 1
  store i32 %780, ptr %3, align 4
  %781 = load i32, ptr %3, align 4
  %782 = icmp slt i32 %781, 1000
  br i1 %782, label %783, label %1087

783:                                              ; preds = %778
  %784 = load i32, ptr %3, align 4
  %785 = sext i32 %784 to i64
  %786 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %785
  store i32 0, ptr %786, align 4
  br label %787

787:                                              ; preds = %783
  %788 = load i32, ptr %3, align 4
  %789 = add nsw i32 %788, 1
  store i32 %789, ptr %3, align 4
  %790 = load i32, ptr %3, align 4
  %791 = icmp slt i32 %790, 1000
  br i1 %791, label %792, label %1087

792:                                              ; preds = %787
  %793 = load i32, ptr %3, align 4
  %794 = sext i32 %793 to i64
  %795 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %794
  store i32 0, ptr %795, align 4
  br label %796

796:                                              ; preds = %792
  %797 = load i32, ptr %3, align 4
  %798 = add nsw i32 %797, 1
  store i32 %798, ptr %3, align 4
  %799 = load i32, ptr %3, align 4
  %800 = icmp slt i32 %799, 1000
  br i1 %800, label %801, label %1087

801:                                              ; preds = %796
  %802 = load i32, ptr %3, align 4
  %803 = sext i32 %802 to i64
  %804 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %803
  store i32 0, ptr %804, align 4
  br label %805

805:                                              ; preds = %801
  %806 = load i32, ptr %3, align 4
  %807 = add nsw i32 %806, 1
  store i32 %807, ptr %3, align 4
  %808 = load i32, ptr %3, align 4
  %809 = icmp slt i32 %808, 1000
  br i1 %809, label %810, label %1087

810:                                              ; preds = %805
  %811 = load i32, ptr %3, align 4
  %812 = sext i32 %811 to i64
  %813 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %812
  store i32 0, ptr %813, align 4
  br label %814

814:                                              ; preds = %810
  %815 = load i32, ptr %3, align 4
  %816 = add nsw i32 %815, 1
  store i32 %816, ptr %3, align 4
  %817 = load i32, ptr %3, align 4
  %818 = icmp slt i32 %817, 1000
  br i1 %818, label %819, label %1087

819:                                              ; preds = %814
  %820 = load i32, ptr %3, align 4
  %821 = sext i32 %820 to i64
  %822 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %821
  store i32 0, ptr %822, align 4
  br label %823

823:                                              ; preds = %819
  %824 = load i32, ptr %3, align 4
  %825 = add nsw i32 %824, 1
  store i32 %825, ptr %3, align 4
  %826 = load i32, ptr %3, align 4
  %827 = icmp slt i32 %826, 1000
  br i1 %827, label %828, label %1087

828:                                              ; preds = %823
  %829 = load i32, ptr %3, align 4
  %830 = sext i32 %829 to i64
  %831 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %830
  store i32 0, ptr %831, align 4
  br label %832

832:                                              ; preds = %828
  %833 = load i32, ptr %3, align 4
  %834 = add nsw i32 %833, 1
  store i32 %834, ptr %3, align 4
  %835 = load i32, ptr %3, align 4
  %836 = icmp slt i32 %835, 1000
  br i1 %836, label %837, label %1087

837:                                              ; preds = %832
  %838 = load i32, ptr %3, align 4
  %839 = sext i32 %838 to i64
  %840 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %839
  store i32 0, ptr %840, align 4
  br label %841

841:                                              ; preds = %837
  %842 = load i32, ptr %3, align 4
  %843 = add nsw i32 %842, 1
  store i32 %843, ptr %3, align 4
  %844 = load i32, ptr %3, align 4
  %845 = icmp slt i32 %844, 1000
  br i1 %845, label %846, label %1087

846:                                              ; preds = %841
  %847 = load i32, ptr %3, align 4
  %848 = sext i32 %847 to i64
  %849 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %848
  store i32 0, ptr %849, align 4
  br label %850

850:                                              ; preds = %846
  %851 = load i32, ptr %3, align 4
  %852 = add nsw i32 %851, 1
  store i32 %852, ptr %3, align 4
  %853 = load i32, ptr %3, align 4
  %854 = icmp slt i32 %853, 1000
  br i1 %854, label %855, label %1087

855:                                              ; preds = %850
  %856 = load i32, ptr %3, align 4
  %857 = sext i32 %856 to i64
  %858 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %857
  store i32 0, ptr %858, align 4
  br label %859

859:                                              ; preds = %855
  %860 = load i32, ptr %3, align 4
  %861 = add nsw i32 %860, 1
  store i32 %861, ptr %3, align 4
  %862 = load i32, ptr %3, align 4
  %863 = icmp slt i32 %862, 1000
  br i1 %863, label %864, label %1087

864:                                              ; preds = %859
  %865 = load i32, ptr %3, align 4
  %866 = sext i32 %865 to i64
  %867 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %866
  store i32 0, ptr %867, align 4
  br label %868

868:                                              ; preds = %864
  %869 = load i32, ptr %3, align 4
  %870 = add nsw i32 %869, 1
  store i32 %870, ptr %3, align 4
  %871 = load i32, ptr %3, align 4
  %872 = icmp slt i32 %871, 1000
  br i1 %872, label %873, label %1087

873:                                              ; preds = %868
  %874 = load i32, ptr %3, align 4
  %875 = sext i32 %874 to i64
  %876 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %875
  store i32 0, ptr %876, align 4
  br label %877

877:                                              ; preds = %873
  %878 = load i32, ptr %3, align 4
  %879 = add nsw i32 %878, 1
  store i32 %879, ptr %3, align 4
  %880 = load i32, ptr %3, align 4
  %881 = icmp slt i32 %880, 1000
  br i1 %881, label %882, label %1087

882:                                              ; preds = %877
  %883 = load i32, ptr %3, align 4
  %884 = sext i32 %883 to i64
  %885 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %884
  store i32 0, ptr %885, align 4
  br label %886

886:                                              ; preds = %882
  %887 = load i32, ptr %3, align 4
  %888 = add nsw i32 %887, 1
  store i32 %888, ptr %3, align 4
  %889 = load i32, ptr %3, align 4
  %890 = icmp slt i32 %889, 1000
  br i1 %890, label %891, label %1087

891:                                              ; preds = %886
  %892 = load i32, ptr %3, align 4
  %893 = sext i32 %892 to i64
  %894 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %893
  store i32 0, ptr %894, align 4
  br label %895

895:                                              ; preds = %891
  %896 = load i32, ptr %3, align 4
  %897 = add nsw i32 %896, 1
  store i32 %897, ptr %3, align 4
  %898 = load i32, ptr %3, align 4
  %899 = icmp slt i32 %898, 1000
  br i1 %899, label %900, label %1087

900:                                              ; preds = %895
  %901 = load i32, ptr %3, align 4
  %902 = sext i32 %901 to i64
  %903 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %902
  store i32 0, ptr %903, align 4
  br label %904

904:                                              ; preds = %900
  %905 = load i32, ptr %3, align 4
  %906 = add nsw i32 %905, 1
  store i32 %906, ptr %3, align 4
  %907 = load i32, ptr %3, align 4
  %908 = icmp slt i32 %907, 1000
  br i1 %908, label %909, label %1087

909:                                              ; preds = %904
  %910 = load i32, ptr %3, align 4
  %911 = sext i32 %910 to i64
  %912 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %911
  store i32 0, ptr %912, align 4
  br label %913

913:                                              ; preds = %909
  %914 = load i32, ptr %3, align 4
  %915 = add nsw i32 %914, 1
  store i32 %915, ptr %3, align 4
  %916 = load i32, ptr %3, align 4
  %917 = icmp slt i32 %916, 1000
  br i1 %917, label %918, label %1087

918:                                              ; preds = %913
  %919 = load i32, ptr %3, align 4
  %920 = sext i32 %919 to i64
  %921 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %920
  store i32 0, ptr %921, align 4
  br label %922

922:                                              ; preds = %918
  %923 = load i32, ptr %3, align 4
  %924 = add nsw i32 %923, 1
  store i32 %924, ptr %3, align 4
  %925 = load i32, ptr %3, align 4
  %926 = icmp slt i32 %925, 1000
  br i1 %926, label %927, label %1087

927:                                              ; preds = %922
  %928 = load i32, ptr %3, align 4
  %929 = sext i32 %928 to i64
  %930 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %929
  store i32 0, ptr %930, align 4
  br label %931

931:                                              ; preds = %927
  %932 = load i32, ptr %3, align 4
  %933 = add nsw i32 %932, 1
  store i32 %933, ptr %3, align 4
  %934 = load i32, ptr %3, align 4
  %935 = icmp slt i32 %934, 1000
  br i1 %935, label %936, label %1087

936:                                              ; preds = %931
  %937 = load i32, ptr %3, align 4
  %938 = sext i32 %937 to i64
  %939 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %938
  store i32 0, ptr %939, align 4
  br label %940

940:                                              ; preds = %936
  %941 = load i32, ptr %3, align 4
  %942 = add nsw i32 %941, 1
  store i32 %942, ptr %3, align 4
  %943 = load i32, ptr %3, align 4
  %944 = icmp slt i32 %943, 1000
  br i1 %944, label %945, label %1087

945:                                              ; preds = %940
  %946 = load i32, ptr %3, align 4
  %947 = sext i32 %946 to i64
  %948 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %947
  store i32 0, ptr %948, align 4
  br label %949

949:                                              ; preds = %945
  %950 = load i32, ptr %3, align 4
  %951 = add nsw i32 %950, 1
  store i32 %951, ptr %3, align 4
  %952 = load i32, ptr %3, align 4
  %953 = icmp slt i32 %952, 1000
  br i1 %953, label %954, label %1087

954:                                              ; preds = %949
  %955 = load i32, ptr %3, align 4
  %956 = sext i32 %955 to i64
  %957 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %956
  store i32 0, ptr %957, align 4
  br label %958

958:                                              ; preds = %954
  %959 = load i32, ptr %3, align 4
  %960 = add nsw i32 %959, 1
  store i32 %960, ptr %3, align 4
  %961 = load i32, ptr %3, align 4
  %962 = icmp slt i32 %961, 1000
  br i1 %962, label %963, label %1087

963:                                              ; preds = %958
  %964 = load i32, ptr %3, align 4
  %965 = sext i32 %964 to i64
  %966 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %965
  store i32 0, ptr %966, align 4
  br label %967

967:                                              ; preds = %963
  %968 = load i32, ptr %3, align 4
  %969 = add nsw i32 %968, 1
  store i32 %969, ptr %3, align 4
  %970 = load i32, ptr %3, align 4
  %971 = icmp slt i32 %970, 1000
  br i1 %971, label %972, label %1087

972:                                              ; preds = %967
  %973 = load i32, ptr %3, align 4
  %974 = sext i32 %973 to i64
  %975 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %974
  store i32 0, ptr %975, align 4
  br label %976

976:                                              ; preds = %972
  %977 = load i32, ptr %3, align 4
  %978 = add nsw i32 %977, 1
  store i32 %978, ptr %3, align 4
  %979 = load i32, ptr %3, align 4
  %980 = icmp slt i32 %979, 1000
  br i1 %980, label %981, label %1087

981:                                              ; preds = %976
  %982 = load i32, ptr %3, align 4
  %983 = sext i32 %982 to i64
  %984 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %983
  store i32 0, ptr %984, align 4
  br label %985

985:                                              ; preds = %981
  %986 = load i32, ptr %3, align 4
  %987 = add nsw i32 %986, 1
  store i32 %987, ptr %3, align 4
  %988 = load i32, ptr %3, align 4
  %989 = icmp slt i32 %988, 1000
  br i1 %989, label %990, label %1087

990:                                              ; preds = %985
  %991 = load i32, ptr %3, align 4
  %992 = sext i32 %991 to i64
  %993 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %992
  store i32 0, ptr %993, align 4
  br label %994

994:                                              ; preds = %990
  %995 = load i32, ptr %3, align 4
  %996 = add nsw i32 %995, 1
  store i32 %996, ptr %3, align 4
  %997 = load i32, ptr %3, align 4
  %998 = icmp slt i32 %997, 1000
  br i1 %998, label %999, label %1087

999:                                              ; preds = %994
  %1000 = load i32, ptr %3, align 4
  %1001 = sext i32 %1000 to i64
  %1002 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %1001
  store i32 0, ptr %1002, align 4
  br label %1003

1003:                                             ; preds = %999
  %1004 = load i32, ptr %3, align 4
  %1005 = add nsw i32 %1004, 1
  store i32 %1005, ptr %3, align 4
  %1006 = load i32, ptr %3, align 4
  %1007 = icmp slt i32 %1006, 1000
  br i1 %1007, label %1008, label %1087

1008:                                             ; preds = %1003
  %1009 = load i32, ptr %3, align 4
  %1010 = sext i32 %1009 to i64
  %1011 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %1010
  store i32 0, ptr %1011, align 4
  br label %1012

1012:                                             ; preds = %1008
  %1013 = load i32, ptr %3, align 4
  %1014 = add nsw i32 %1013, 1
  store i32 %1014, ptr %3, align 4
  %1015 = load i32, ptr %3, align 4
  %1016 = icmp slt i32 %1015, 1000
  br i1 %1016, label %1017, label %1087

1017:                                             ; preds = %1012
  %1018 = load i32, ptr %3, align 4
  %1019 = sext i32 %1018 to i64
  %1020 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %1019
  store i32 0, ptr %1020, align 4
  br label %1021

1021:                                             ; preds = %1017
  %1022 = load i32, ptr %3, align 4
  %1023 = add nsw i32 %1022, 1
  store i32 %1023, ptr %3, align 4
  %1024 = load i32, ptr %3, align 4
  %1025 = icmp slt i32 %1024, 1000
  br i1 %1025, label %1026, label %1087

1026:                                             ; preds = %1021
  %1027 = load i32, ptr %3, align 4
  %1028 = sext i32 %1027 to i64
  %1029 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %1028
  store i32 0, ptr %1029, align 4
  br label %1030

1030:                                             ; preds = %1026
  %1031 = load i32, ptr %3, align 4
  %1032 = add nsw i32 %1031, 1
  store i32 %1032, ptr %3, align 4
  %1033 = load i32, ptr %3, align 4
  %1034 = icmp slt i32 %1033, 1000
  br i1 %1034, label %1035, label %1087

1035:                                             ; preds = %1030
  %1036 = load i32, ptr %3, align 4
  %1037 = sext i32 %1036 to i64
  %1038 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %1037
  store i32 0, ptr %1038, align 4
  br label %1039

1039:                                             ; preds = %1035
  %1040 = load i32, ptr %3, align 4
  %1041 = add nsw i32 %1040, 1
  store i32 %1041, ptr %3, align 4
  %1042 = load i32, ptr %3, align 4
  %1043 = icmp slt i32 %1042, 1000
  br i1 %1043, label %1044, label %1087

1044:                                             ; preds = %1039
  %1045 = load i32, ptr %3, align 4
  %1046 = sext i32 %1045 to i64
  %1047 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %1046
  store i32 0, ptr %1047, align 4
  br label %1048

1048:                                             ; preds = %1044
  %1049 = load i32, ptr %3, align 4
  %1050 = add nsw i32 %1049, 1
  store i32 %1050, ptr %3, align 4
  %1051 = load i32, ptr %3, align 4
  %1052 = icmp slt i32 %1051, 1000
  br i1 %1052, label %1053, label %1087

1053:                                             ; preds = %1048
  %1054 = load i32, ptr %3, align 4
  %1055 = sext i32 %1054 to i64
  %1056 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %1055
  store i32 0, ptr %1056, align 4
  br label %1057

1057:                                             ; preds = %1053
  %1058 = load i32, ptr %3, align 4
  %1059 = add nsw i32 %1058, 1
  store i32 %1059, ptr %3, align 4
  %1060 = load i32, ptr %3, align 4
  %1061 = icmp slt i32 %1060, 1000
  br i1 %1061, label %1062, label %1087

1062:                                             ; preds = %1057
  %1063 = load i32, ptr %3, align 4
  %1064 = sext i32 %1063 to i64
  %1065 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %1064
  store i32 0, ptr %1065, align 4
  br label %1066

1066:                                             ; preds = %1062
  %1067 = load i32, ptr %3, align 4
  %1068 = add nsw i32 %1067, 1
  store i32 %1068, ptr %3, align 4
  %1069 = load i32, ptr %3, align 4
  %1070 = icmp slt i32 %1069, 1000
  br i1 %1070, label %1071, label %1087

1071:                                             ; preds = %1066
  %1072 = load i32, ptr %3, align 4
  %1073 = sext i32 %1072 to i64
  %1074 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %1073
  store i32 0, ptr %1074, align 4
  br label %1075

1075:                                             ; preds = %1071
  %1076 = load i32, ptr %3, align 4
  %1077 = add nsw i32 %1076, 1
  store i32 %1077, ptr %3, align 4
  %1078 = load i32, ptr %3, align 4
  %1079 = icmp slt i32 %1078, 1000
  br i1 %1079, label %1080, label %1087

1080:                                             ; preds = %1075
  %1081 = load i32, ptr %3, align 4
  %1082 = sext i32 %1081 to i64
  %1083 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %1082
  store i32 0, ptr %1083, align 4
  br label %1084

1084:                                             ; preds = %1080
  %1085 = load i32, ptr %3, align 4
  %1086 = add nsw i32 %1085, 1
  store i32 %1086, ptr %3, align 4
  br label %6, !llvm.loop !6

1087:                                             ; preds = %1075, %1066, %1057, %1048, %1039, %1030, %1021, %1012, %1003, %994, %985, %976, %967, %958, %949, %940, %931, %922, %913, %904, %895, %886, %877, %868, %859, %850, %841, %832, %823, %814, %805, %796, %787, %778, %769, %760, %751, %742, %733, %724, %715, %706, %697, %688, %679, %670, %661, %652, %643, %634, %625, %616, %607, %598, %589, %580, %571, %562, %553, %544, %535, %526, %517, %508, %499, %490, %481, %472, %463, %454, %445, %436, %427, %418, %409, %400, %391, %382, %373, %364, %355, %346, %337, %328, %319, %310, %301, %292, %283, %274, %265, %256, %247, %238, %229, %220, %211, %202, %193, %184, %175, %166, %157, %148, %139, %130, %121, %112, %103, %94, %85, %76, %67, %58, %49, %40, %31, %22, %13, %6
  store i32 100, ptr %4, align 4
  br label %1088

1088:                                             ; preds = %1097, %1087
  %1089 = load i32, ptr %4, align 4
  %1090 = icmp slt i32 %1089, 1000
  br i1 %1090, label %1091, label %1100

1091:                                             ; preds = %1088
  %1092 = load i32, ptr %4, align 4
  %1093 = sext i32 %1092 to i64
  %1094 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %1093
  %1095 = load i32, ptr %1094, align 4
  %1096 = add nsw i32 %1095, 10
  store i32 %1096, ptr %1094, align 4
  br label %1097

1097:                                             ; preds = %1091
  %1098 = load i32, ptr %4, align 4
  %1099 = add nsw i32 %1098, 1
  store i32 %1099, ptr %4, align 4
  br label %1088, !llvm.loop !8

1100:                                             ; preds = %1088
  %1101 = call i32 @bar(i32 noundef 2023)
  store i32 0, ptr %3, align 4
  br label %1102

1102:                                             ; preds = %1112, %1100
  %1103 = load i32, ptr %3, align 4
  %1104 = icmp slt i32 %1103, 1000
  br i1 %1104, label %1105, label %1115

1105:                                             ; preds = %1102
  %1106 = load ptr, ptr @stdout, align 8
  %1107 = load i32, ptr %3, align 4
  %1108 = sext i32 %1107 to i64
  %1109 = getelementptr inbounds [1000 x i32], ptr %2, i64 0, i64 %1108
  %1110 = load i32, ptr %1109, align 4
  %1111 = call i32 (ptr, ptr, ...) @fprintf(ptr noundef %1106, ptr noundef @.str.1, i32 noundef %1110)
  br label %1112

1112:                                             ; preds = %1105
  %1113 = load i32, ptr %3, align 4
  %1114 = add nsw i32 %1113, 1
  store i32 %1114, ptr %3, align 4
  br label %1102, !llvm.loop !9

1115:                                             ; preds = %1102
  ret i32 1
}

declare i32 @fprintf(ptr noundef, ptr noundef, ...) #1

attributes #0 = { noinline nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 18.1.8 (https://github.com/llvm/llvm-project.git 3b5b5c1ec4a3095ab096dd780e84d7ab81f3d7ff)"}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
!8 = distinct !{!8, !7}
!9 = distinct !{!9, !7}
